#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Функция для вычисления префиксной функции для шаблона
vector<int> computePrefixFunction(const string& pattern) {
    int m = pattern.size();
    vector<int> prefix(m);
    int k = 0;

    for (int i = 1; i < m; ++i) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            k++;
        }
        prefix[i] = k;
    }

    return prefix;
}

// Функция для поиска шаблона в тексте с использованием алгоритма Кнута-Морриса-Пратта
vector<int> KMPSearch(const string& text, const string& pattern) {
    vector<int> prefix = computePrefixFunction(pattern);
    vector<int> result;
    int n = text.size();
    int m = pattern.size();
    int k = 0;

    for (int i = 0; i < n; ++i) {
        while (k > 0 && pattern[k] != text[i]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == text[i]) {
            k++;
        }
        if (k == m) {
            result.push_back(i - m + 1);
            k = prefix[k - 1];
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
    string filename = "input.txt"; // Замените на ваш файл
    string pattern;

    cout << "Введите строку поиска: ";
    getline(cin, pattern);

    string text = readTextFromFile(filename);
    if (text.empty()) {
        return 1;
    }

    vector<int> positions = KMPSearch(text, pattern);

    if (!positions.empty()) {
        cout << "Строка '" << pattern << "' найдена в позициях: ";
        for (int pos : positions) {
            cout << pos << " ";
        }
        cout << std::endl;
    }
    else {
        cout << "Строка '" << pattern << "' не найдена." << endl;
    }

    return 0;
}