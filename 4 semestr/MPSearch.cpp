#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// ������� ��� ���������� ���������� ������� ��� �������
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

// ������� ��� ������ ������� � ������ � �������������� ��������� �����-�������-������
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

// ������� ��� ������ ������ �� �����
string readTextFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "�� ������� ������� ����: " << filename << endl;
        return "";
    }

    string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return text;
}

int main() {
    string filename = "input.txt"; // �������� �� ��� ����
    string pattern;

    cout << "������� ������ ������: ";
    getline(cin, pattern);

    string text = readTextFromFile(filename);
    if (text.empty()) {
        return 1;
    }

    vector<int> positions = KMPSearch(text, pattern);

    if (!positions.empty()) {
        cout << "������ '" << pattern << "' ������� � ��������: ";
        for (int pos : positions) {
            cout << pos << " ";
        }
        cout << std::endl;
    }
    else {
        cout << "������ '" << pattern << "' �� �������." << endl;
    }

    return 0;
}