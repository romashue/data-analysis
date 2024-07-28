#include <iostream>
using namespace std;

int main() {


	const int N = 10; // размер будущего массива
	int mas[N];
	for (int i = 0; i < N; i++) {
		mas[i] = rand() % 51; // заполняем массив рандомными числам до 50
		cout << mas[i] << endl;
	}
	int k = 0;
	while (k != N) {
		int min = k;
		for (int i = k; i < N; i++) {
			if (mas[min] < mas[i]) {
				min = i;
			}
		}
		swap(mas[k], mas[min]);
		k++;
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << mas[i] << endl;
	}
	cout << endl;
	for (int i = N - 1; i >= 0; i--) {
		cout << mas[i] << endl;
	}

	return 0;
}