#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Функция для нахождения подмножества с заданной суммой с использованием жадного алгоритма
bool subsetSum(const vector<int>& nums, int targetSum, vector<int>& result) {
    int currentSum = 0;
    result.clear();

    // Копируем массив и сортируем его в порядке убывания
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end(), greater<int>());

    for (int num : sortedNums) {
        if (currentSum + num <= targetSum) {
            currentSum += num;
            result.push_back(num);

            if (currentSum == targetSum) {
                return true;
            }
        }
    }

    return false; // Если не удалось найти подмножество с заданной суммой
}

// Функция для чтения чисел из файла
vector<int> readNumbersFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл: " << filename << endl;
        exit(1);
    }

    int n;
    file >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        file >> nums[i];
    }

    file.close();
    return nums;
}

int main() {

    setlocale(LC_ALL, "Russian");

    string filename = "numbers.txt"; 
    int targetSum;

    cout << "Введите целевую сумму: ";
    cin >> targetSum;

    vector<int> nums = readNumbersFromFile(filename);
    vector<int> result;

    if (subsetSum(nums, targetSum, result)) {
        cout << "Найдено подмножество с заданной суммой: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    else {
        cout << "Не удалось найти подмножество с заданной суммой." << endl;
    }

    return 0;
}