#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Функция для построения таблицы "плохих символов"
unordered_map<char, int> buildBadCharTable(const string& pattern) {
    unordered_map<char, int> badCharTable;
    int m = pattern.size();

    for (int i = 0; i < m - 1; ++i) {
        badCharTable[pattern[i]] = i;
    }

    return badCharTable;
}

// Функция для построения таблицы "хороших суффиксов"
vector<int> buildGoodSuffixTable(const string& pattern) {
    int m = pattern.size();
    vector<int> goodSuffixTable(m, m);

    vector<int> suffix(m, 0);
    suffix[m - 1] = m;
    int g = m - 1;
    int f = 0;

    for (int i = m - 2; i >= 0; --i) {
        if (i > g && suffix[i + m - 1 - f] < i - g) {
            suffix[i] = suffix[i + m - 1 - f];
        }
        else {
            if (i < g) {
                g = i;
            }
            f = i;
            while (g >= 0 && pattern[g] == pattern[g + m - 1 - f]) {
                g--;
            }
            suffix[i] = f - g;
        }
    }

    for (int i = 0; i < m - 1; ++i) {
        goodSuffixTable[m - 1 - suffix[i]] = m - 1 - i;
    }

    return goodSuffixTable;
}

// Функция для поиска шаблона в тексте с использованием алгоритма Бойера-Мура
vector<int> BoyerMooreSearch(const string& text, const string& pattern) {
    unordered_map<char, int> badCharTable = buildBadCharTable(pattern);
    vector<int> goodSuffixTable = buildGoodSuffixTable(pattern);
    vector<int> result;

    int n = text.size();
    int m = pattern.size();
    int s = 0;

    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }
        if (j < 0) {
            result.push_back(s);
            s += goodSuffixTable[0];
        }
        else {
            int badCharShift = (badCharTable.find(text[s + j]) != badCharTable.end()) ? j - badCharTable[text[s + j]] : j + 1;
            int goodSuffixShift = goodSuffixTable[j];
            s += max(badCharShift, goodSuffixShift);
        }
    }

    return result;
}

// Функция для чтения текста из файла
string readTextFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл: " << filename << endl;
        return "";
    }

    string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return text;
}

int main() {

    setlocale(LC_ALL, "Russian");

    string filename = "input.txt"; 
    string pattern;

    cout << "Введите строку поиска: ";
    getline(cin, pattern);

    string text = readTextFromFile(filename);
    if (text.empty()) {
        return 1;
    }

    vector<int> positions = BoyerMooreSearch(text, pattern);

    if (!positions.empty()) {
        cout << "Строка '" << pattern << "' найдена в позициях: ";
        for (int pos : positions) {
            cout << pos << " ";
        }
        cout << endl;
    }
    else {
        cout << "Строка '" << pattern << "' не найдена." << endl;
    }

    return 0;
}