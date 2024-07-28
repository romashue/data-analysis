#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// ��������� ��� �����������
const int d = 256; // ������ ��������
const int q = 101; // ������� ����� ��� ���������� ����

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

// ������� ��� ������ ������� � ������ � �������������� ��������� ������-�����
vector<int> RabinKarpSearch(const string& text, const string& pattern) {
    vector<int> result;
    int n = text.size();
    int m = pattern.size();
    int h = 1; // �������� h ����� �������������� ��� ���������� ����
    int p = 0; // ��� ��� �������
    int t = 0; // ��� ��� ������

    // ��������� �������� h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; ++i) {
        h = (h * d) % q;
    }

    // ��������� ��������� ���� ��� ������� � ������� ���� ������
    for (int i = 0; i < m; ++i) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // �������� ���� �� ������ �� ���� ������� �� ���
    for (int s = 0; s <= n - m; ++s) {
        // ��������� ���������� �����
        if (p == t) {
            // ���� ���� ���������, ��������� �������
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

        // ��������� ��� ��� ���������� ���� ������
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

    cout << "������� ������ ������: ";
    getline(cin, pattern);

    string text = readTextFromFile(filename);
    if (text.empty()) {
        return 1;
    }

    vector<int> positions = RabinKarpSearch(text, pattern);

    if (!positions.empty()) {
        cout << "������ '" << pattern << "' ������� � ��������: ";
        for (int pos : positions) {
            cout << pos << " ";
        }
        cout << endl;
    }
    else {
        cout << "������ '" << pattern << "' �� �������." << endl;
    }

    return 0;
}