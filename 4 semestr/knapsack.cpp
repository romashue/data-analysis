#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Структура для представления предмета
struct Item {
    int value;
    int weight;
};

// Функция для решения задачи о рюкзаке
int knapsack(int W, const vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    // Построение таблицы K[][] в нижнем направлении
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            else if (items[i - 1].weight <= w) {
                K[i][w] = std::max(items[i - 1].value + K[i - 1][w - items[i - 1].weight], K[i - 1][w]);
            }
            else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W];
}

// Функция для чтения предметов из файла
vector<Item> readItemsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл: " << filename << endl;
        exit(1);
    }

    int n;
    file >> n;
    std::vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        file >> items[i].value >> items[i].weight;
    }

    file.close();
    return items;
}

int main() {

    setlocale(LC_ALL, "Russian");

    string filename = "items.txt"; 
    int W;

    cout << "Введите максимальный вес рюкзака: ";
    cin >> W;

    vector<Item> items = readItemsFromFile(filename);

    int max_value = knapsack(W, items);

    cout << "Максимальная стоимость, которую можно получить: " << max_value << endl;

    return 0;
}