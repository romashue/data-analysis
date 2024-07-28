#include <iostream>
using namespace std;

int main() {

	const int N = 11; // размер будущего массива
	int mas[N];
	for (int i = 0; i < N; i++) {
		mas[i] = rand() % 101; // заполняем массив рандомными числам до 110
	/*	std::cout << mas[i] << endl;*/
	}
	int div = static_cast<int> (N / 2);
	while (div != 0) {
		for (int i = div; i < N; i++) {
			int j = i;
			while ((j >= div) && (mas[j] < (mas[j - div]))) {
				swap(mas[j], mas[j-div]);
				j = j - div;
			}
			std::cout << endl;
			for (int k = 0; k < N; k++) {
				std::cout << mas[k] << endl;
			}
		}
		div = static_cast<int> (div / 2);
	}
	return 0;
}