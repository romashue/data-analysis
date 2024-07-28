#include<iostream>
#include <vector>
#include <cmath>
using namespace std;
# define M_PI           3.14159265358979323846 
int main() {
	vector<double> stack;
	vector<double> stack_X;
	vector<double> stack_Y;
	int N = 0;
	cout << "Vvedite skolko tochek bydet" << endl;
	cin >> N;
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << "vvedite koordinati tochki nomer " << i + 1 << endl;
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				double a = 0;
				cin >> a;
				stack_X.push_back(a);
			}
			if (j == 1) {
				double a = 0;
				cin >> a;
				stack_Y.push_back(a);
			}
		}
	}
	double start = stack_X[0];
	for (int i = 0; i < N; i++) {
		if (start > stack_X[i]) {
			swap(stack_X[i], stack_X[0]);
			swap(stack_Y[i], stack_Y[0]);
			cout << endl;
			cout << start << endl;
		}
	}
	cout << "START TOCHKA: " << "(" << stack_X[0] << ";" << stack_Y[0] << ")" << endl;
	for (int i = 0; i < N; i++) {
		cout << "(" << stack_X[i] << ";" << stack_Y[i] << ")" << endl;
	}

	//новые вектора с которыми буду проводить манипуляции
	vector<double> stack_X1;
	vector<double> stack_Y1;

	//создаю новую систему координат относительно стартовой точки
	for (int i = 0; i < N; i++) {
		stack_X1.push_back(stack_X[i]- stack_X[0]);
		stack_Y1.push_back(stack_Y[i] - stack_Y[0]);
	}
	cout << "--------------------------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << "(" << stack_X1[i] << ";" << stack_Y1[i] << ")" << endl;
	}
	cout << endl;
	//перевод в полярную систему координат относительно стартовой точки.
	for (int i = 1; i < N; i++) {
		double tmp = stack_X1[i];
		stack_X1[i] = sqrt(stack_X1[i] * stack_X1[i] + stack_Y1[i] * stack_Y1[i]);
		if (tmp!=0)
		{
			stack_Y1[i] = atan(stack_Y1[i] / tmp)*180/ M_PI; // Чтобы было в градусах
		}
		// добавить условие, так как  может оказаться, что координата по Х у стартовой
		// с нынешней могут совпасть
	}

	cout << "--------------------------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << "(" << stack_X1[i] << ";" << stack_Y1[i] << ")" << endl;
	}
	//осталось: ВРОДЕ РАБОТАЕТ
	// Проверяю на 
	// 1 1
	// 2 3
	// 3 2
	// 4 6
	// 1. осортировать относительно против часовой стрелки через
	// векторное произведение, если >0, то первый множитель идет 
	// раньше второго множителя, если <0, то первый множитель идет
	// после второго множителя.
	for (int i = 1; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if ((stack_Y1[j] - stack_Y1[i]) < 0) {
				swap(stack_X1[i], stack_X1[j]);
				swap(stack_Y1[i], stack_Y1[j]);

				swap(stack_X[i], stack_X[j]);
				swap(stack_Y[i], stack_Y[j]);

				cout << endl;
				cout << "nomer = " << i << endl;
				for (int i = 0; i < N; i++) {
					cout << "(" << stack_X1[i] << ";" << stack_Y1[i] << ")" << endl;
				}
				cout << endl;
				for (int i = 0; i < N; i++) {
					cout << "(" << stack_X[i] << ";" << stack_Y[i] << ")" << endl;
				}
			}
		}
	}
	cout << "--------------------------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << "(" << stack_X1[i] << ";" << stack_Y1[i] << ")" << endl;
	}
	cout << endl;
	cout << endl;


	for (int i = 0; i < N; i++) {
		cout << "(" << stack_X[i] << ";" << stack_Y[i] << ")" << endl;
	}

	// 2. Построение самой оболочки. Мы строим прямые, а потом смотрим, будет ли внутренний угол 
	// больше 180 градусов, если так, то мы исключаем/пропускаем точку из построения оболочки. И дальше
	// мы идем назад ДО ТЕХ ПОР, пока не будет удовлетворять условию. По итогу мы получаем оболочку :D

	return 0;
}