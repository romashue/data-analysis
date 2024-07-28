#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Константы для хеширования
const int d = 256; // Размер алфавита
const int q = 101; // Простое число для вычисления хеша

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

// Функция для поиска шаблона в тексте с использованием алгоритма Рабина-Карпа
vector<int> RabinKarpSearch(const string& text, const string& pattern) {
    vector<int> result;
    int n = text.size();
    int m = pattern.size();
    int h = 1; // Значение h будет использоваться для вычисления хеша
    int p = 0; // Хеш для шаблона
    int t = 0; // Хеш для текста

    // Вычисляем значение h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; ++i) {
        h = (h * d) % q;
    }

    // Вычисляем начальные хеши для шаблона и первого окна текста
    for (int i = 0; i < m; ++i) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Сдвигаем окно по тексту на одну позицию за раз
    for (int s = 0; s <= n - m; ++s) {
        // Проверяем совпадение хешей
        if (p == t) {
            // Если хеши совпадают, проверяем символы
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (text[s + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.push_back(s);
            }
        }

        // Вычисляем хеш для следующего окна текста
        if (s < n - m) {
            t = (d * (t - text[s] * h) + text[s + m]) % q;
            if (t < 0) {
                t = (t + q);
            }
        }
    }

    return result;
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

    vector<int> positions = RabinKarpSearch(text, pattern);

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