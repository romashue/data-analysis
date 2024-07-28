#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// Функция для раскладки предметов по ящикам с использованием жадного алгоритма First Fit
int firstFit(const vector<int>& weights, int binCapacity) {
    // Вектор для хранения текущей заполненности ящиков
    std::vector<int> binRemaining;

    // Проходим по всем предметам
    for (int weight : weights) {
        bool placed = false;

        // Ищем первый ящик, в который поместится текущий предмет
        for (int i = 0; i < binRemaining.size(); ++i) {
            if (binRemaining[i] >= weight) {
                binRemaining[i] -= weight;
                placed = true;
                break;
            }
        }

        // Если не нашли подходящий ящик, создаем новый
        if (!placed) {
            binRemaining.push_back(binCapacity - weight);
        }
    }

    // Возвращаем количество использованных ящиков
    return binRemaining.size();
}

// Функция для чтения весов предметов из файла
vector<int> readWeightsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл: " << filename << endl;
        exit(1);
    }

    int n;
    file >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        file >> weights[i];
    }

    file.close();
    return weights;
}

int main() {

    setlocale(LC_ALL, "Russian");

    string filename = "weights.txt"; 
    int binCapacity;

    cout << "Введите вместимость ящика: ";
    cin >> binCapacity;

    vector<int> weights = readWeightsFromFile(filename);

    int numBins = firstFit(weights, binCapacity);

    cout << "Минимальное количество ящиков, необходимых для размещения всех предметов: " << numBins << std::endl;

    return 0;
}