#include <iostream>
using namespace std;

int main() {

	const int N = 10; // ������ �������� �������
	int mas[N];
	for (int i = 0; i < N; i++) {
		mas[i] = rand() % 101; // ��������� ������ ���������� ������ �� 110
		cout << mas[i] << endl;
	}

	for (int i = 1; i < N; i++) {
		for (int j = i; j > 0; j--) {
	
			if (mas[j] < mas[j - 1]) {
				swap(mas[j], mas[j-1]); // ������ �� ��� ���, ���� �� ������� �� �����
			}
			else {
				break;
			}
		}
		cout << endl;
		for (int k = 0; k < N; k++) {
			cout <<  mas[k] << endl;
		}
		
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << mas[i] << endl;
	}
	return 0;
}