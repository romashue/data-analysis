#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void heaping(vector <int>& mas, int size, int mama) {  // ������� ����� ������� �������

    int m_mama = mama; // ��������
    int left_child = 2 * mama + 1;
    int right_child = 2 * mama + 2;
    if ((left_child < size) && (mas[left_child] > mas[m_mama])) {
        m_mama = left_child;
    }
    if ((right_child <size) && (mas[m_mama] < mas[right_child])) {
        m_mama = right_child;
    }
    if (m_mama != mama) {
        swap(mas[mama], mas[m_mama]);
        heaping(mas, size, m_mama); // ��� ��� ��������, �.�. ������� ��������
    }
}
void sortirovka(vector <int>& mas) {

    int razmer = mas.size();
    for (int i = razmer / 2 - 1; i >=0; i--) { // ������ ����
        heaping(mas, razmer, i); // ������, �����������, ������� �������-��������
    }
    for (int i = razmer - 1; i >= 0; i--) {
        cout << endl;
        swap(mas[0], mas[i]); // ������ ����� ������� ������� � �����
        heaping(mas, i, 0);
        for (int j = 0; j < mas.size(); j++) {
            cout << mas[j] << endl;
        }
    }
}


int main() {
    vector<int> mas = { 10, 5, 76, 23, 1, 9, 324, 1, 907, 0 };
    sortirovka(mas);
    cout << endl;
    for (int j = 0; j < mas.size(); j++) {
        cout << mas[j] << endl;
    }
    return 0;
}

