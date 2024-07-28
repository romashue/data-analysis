#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ������� ��� ���������� ������������ � �������� ������ � �������������� ������� ���������
bool subsetSum(const vector<int>& nums, int targetSum, vector<int>& result) {
    int currentSum = 0;
    result.clear();

    // �������� ������ � ��������� ��� � ������� ��������
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

    return false; // ���� �� ������� ����� ������������ � �������� ������
}

// ������� ��� ������ ����� �� �����
vector<int> readNumbersFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "�� ������� ������� ����: " << filename << endl;
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

    cout << "������� ������� �����: ";
    cin >> targetSum;

    vector<int> nums = readNumbersFromFile(filename);
    vector<int> result;

    if (subsetSum(nums, targetSum, result)) {
        cout << "������� ������������ � �������� ������: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    else {
        cout << "�� ������� ����� ������������ � �������� ������." << endl;
    }

    return 0;
}