#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


//vector <int> result(vector <int> mas) {
//	int max = 0;
//	for (int i = 0; i < mas.size(); i++) { // находим самое большое число
//		if (max < mas[i]) {
//			max = mas[i];
//		}
//	}
//	//min
//	int min = max;
//	for (int i = 0; i < mas.size(); i++) { // находим самое маленькое число
//		if (min > mas[i]) {
//			min = mas[i];
//		}
//	}
//	//max
//	int max_digital = 0; // количество разрядов в самом большом числе
//	while (max > 0) {
//		max = static_cast<int>(max / 10);
//		max_digital++;
//	}
//	cout << "max_digital - " << max_digital << endl;
//
//	//min
//
//	int min_digital = 0; // количество разрядов в самом маленьком числе
//	while (min > 0) {
//		min = static_cast<int>(min / 10);
//		min_digital++;
//	}
//	cout << "min_digital - " << min_digital << endl;
//
//	//----------------------------//
//
//	for (int i = min_digital; i <= max_digital; i++) {
//		int temp = static_cast<int>(pow(10, i));
//		for (int j = 0; j < mas.size(); j++) {
//			for (int k = 0; k < mas.size(); k++) {
//				if (((mas[k] % temp) / pow(10, i - 1)) < ((mas[j] % temp) / pow(10, i - 1))) {
//					swap(mas[k], mas[j]);
//
//				}
//			}
//		}
//		cout << endl;
//		for (int t = 0; t < mas.size(); t++)
//		{
//			cout << mas[t] << endl;
//		}
//
//	}
//	return mas;
//}

int main() {

	vector<int> mas = {2761, 551223, 267, 491, 862, 402, 89311, 11};
	//result(mas);
	//max
	int max = 0;
	for (int i = 0; i < mas.size(); i++) { // находим самое большое число
		if (max < mas[i]) {
			max = mas[i];
		}
	}
	//min
	int min = max;
	for (int i = 0; i < mas.size(); i++) { // находим самое маленькое число
		if (min > mas[i]) {
			min = mas[i];
		}
	}
	//max
	int max_digital = 0; // количество разрядов в самом большом числе
	while (max > 0) {
		max = static_cast<int>(max / 10);
		max_digital++;
	}
	cout << "max_digital - " << max_digital << endl;

	//min

	int min_digital = 0; // количество разрядов в самом маленьком числе
	while (min > 0) {
		min = static_cast<int>(min / 10);
		min_digital++;
	}
	cout << "min_digital - " << min_digital << endl;

	//----------------------------//

	for (int i = min_digital; i <= max_digital; i++) {
		int temp = static_cast<int>(pow(10, i));
		for (int j = 0; j < mas.size(); j++) {
			for (int k = 0; k < mas.size(); k++) {
				if (((mas[k] % temp) / pow(10, i - 1)) < ((mas[j] % temp) / pow(10, i - 1))) {
					swap(mas[k], mas[j]);

				}
			}
		}
		cout << endl;
		for (int t = 0; t < mas.size(); t++)
		{
			cout << mas[t] << endl;
		}

	}
	cout << endl;
	for (int i =0; i< mas.size(); i++)
	{
		cout << mas[i] << endl;
	}
	return 0;
}