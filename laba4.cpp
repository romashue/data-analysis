#include <iostream>
using namespace std;

int main() {

	const int N = 10; // ������ �������� �������
	int mas[N];
	for (int i = 0; i < N; i++) {
		mas[i] = rand() % 111; // ��������� ������ ���������� ������ �� 50
		cout << mas[i] << endl;
	}
	int shag = static_cast<int>(N/1.247);
	//cout << endl;
	int swp = 1; // ���������� ������
	while ((shag !=0) or (swp ==0) ) { //���� ��� ����� ���� ��� ������ �� ����, �� ���������� ����.
		swp = 0;
		int k = 0; // �������
		while ((k + shag) <= N) {
			if (mas[k] < mas[k + shag]) {
				swap(mas[k], mas[k + shag]);
				swp++;
				cout << endl;
				for (int i = 0; i < N; i++) {
					cout << mas[i] << endl;
				}
			}
			k++;
		}
		shag = static_cast<int>(shag / 1.247);
		
	}
	cout << endl;
	return 0;
}