#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// ������� ��� ��������� ��������� �� ������ � �������������� ������� ��������� First Fit
int firstFit(const vector<int>& weights, int binCapacity) {
    // ������ ��� �������� ������� ������������� ������
    std::vector<int> binRemaining;

    // �������� �� ���� ���������
    for (int weight : weights) {
        bool placed = false;

        // ���� ������ ����, � ������� ���������� ������� �������
        for (int i = 0; i < binRemaining.size(); ++i) {
            if (binRemaining[i] >= weight) {
                binRemaining[i] -= weight;
                placed = true;
                break;
            }
        }

        // ���� �� ����� ���������� ����, ������� �����
        if (!placed) {
            binRemaining.push_back(binCapacity - weight);
        }
    }

    // ���������� ���������� �������������� ������
    return binRemaining.size();
}

// ������� ��� ������ ����� ��������� �� �����
vector<int> readWeightsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "�� ������� ������� ����: " << filename << endl;
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

    cout << "������� ����������� �����: ";
    cin >> binCapacity;

    vector<int> weights = readWeightsFromFile(filename);

    int numBins = firstFit(weights, binCapacity);

    cout << "����������� ���������� ������, ����������� ��� ���������� ���� ���������: " << numBins << std::endl;

    return 0;
}