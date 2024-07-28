#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// ������� ��� ���������� ��������� �������� ��� �������
vector<unordered_map<char, int>> buildAutomaton(const string& pattern) {
    int m = pattern.size();
    vector<unordered_map<char, int>> automaton(m + 1);

    for (int q = 0; q <= m; ++q) {
        for (char a = ' '; a <= '~'; ++a) { // �������� � ASCII ��������� �� 32 �� 126
            int k = min(m, q + 1);
            while (k > 0 && pattern.substr(0, k) != pattern.substr(0, q) + a) {
                k--;
            }
            automaton[q][a] = k;
        }
    }

    return automaton;
}

// ������� ��� ������ ������� � ������ � �������������� ��������� ��������
vector<int> searchWithAutomaton(const string& text, const string& pattern) {
    auto automaton = buildAutomaton(pattern);
    int state = 0;
    vector<int> result;

    for (int i = 0; i < text.size(); ++i) {
        char c = text[i];
        if (automaton[state].find(c) != automaton[state].end()) {
            state = automaton[state][c];
        }
        else {
            state = 0;
        }

        if (state == pattern.size()) {
            result.push_back(i - pattern.size() + 1);
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

    vector<int> positions = searchWithAutomaton(text, pattern);

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