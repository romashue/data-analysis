#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	vector<int> mas = { 2761, 551223, 267, 491, 862, 402, 89311, 11, 2762 };
	int max = 0;
	for (int i = 0; i < mas.size(); i++) { // находим самое большое число
		if (max < mas[i]) {
			max = mas[i];
		}
	}
	int max_digital = 0; // количество разрядов в самом большом числе
	while (max > 0) {
		max = static_cast<int>(max / 10);
		max_digital++;
	}
	cout << "max_digital - " << max_digital << endl;
	cout << endl;
	for (int t = 0; t < mas.size(); t++)
	{
		cout << mas[t] << endl;
	}
	cout << endl;  

	for (int i = 1; i <= max_digital; i++) {
		int temp = static_cast<int>(pow(10, i));
		for (int j = 0; j < mas.size(); j++) {
			for (int k = 0; k < mas.size(); k++) {
				if (((mas[k] % temp) / pow(10, i - 1)) < ((mas[j] % temp) / pow(10, i - 1))) {
					int lv = (mas[k] % temp) / pow(10, i - 1);
					int pr = (mas[j] % temp) / pow(10, i - 1);
					cout << "lv = " << lv << " pr = " << pr << endl;
					cout << "mas[k] = " << mas[k] << " mas[j] = " << mas[j] << endl;
					swap(mas[k], mas[j]);
				}
			}
		}
		cout << endl;
		cout << "--------------------" << endl;
		for (int t = 0; t < mas.size(); t++)
		{
			cout << mas[t] << endl;
		}
		cout << endl;
	}
	return 0;
}