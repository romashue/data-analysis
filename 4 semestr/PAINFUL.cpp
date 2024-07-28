#include<iostream>
#include <vector>
#include <cmath>
using namespace std;
# define M_PI           3.14159265358979323846 

bool obolochka(double x, double y, double x1, double y1, double x2, double y2) {
	double x3 = 0;
	double y3 = 0;

	double a = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));

	double b13 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	double c3 = sqrt((x - x3) * (x - x3) + (y - y3) * (y - y3));

	double b21 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	double c23 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
	double kap12 = ((-b13 * b13 - a * a + c3 * c3) / (2 * b13 * a));
	double kap22 = ((-b13 * b13 - b21 * b21 + c23 * c23) / (2 * b13 * b21));
	double kap1 = acos(kap12) / M_PI * 180 + acos((-b13 * b13 - b21 * b21 + c23 * c23) / (2 * b13 * b21)) / M_PI * 180;
	if ((y2 > 0) || (y2 < 0 && (((x < x2) && (x2 < x1)) && ((y < y2) && (y2 < y1))))) {

		if (kap1 < 180) {
			cout << "OBchei ygol " << kap1 << endl;
			cout << "Pervei ygol with Pi " << acos(kap12) / M_PI * 180 << endl;
			cout << "Vtor ygol with Pi " << acos(kap22) / M_PI * 180 << endl;
			return true;
		}
		else {
			cout << "A = " << a << " B13 = " << b13 << endl;
			cout << "OBchei ygol " << kap1 << endl;
			cout << "Pervei ygol with Pi " << acos(kap12) / M_PI * 180 << endl;
			cout << "Vtor ygol with Pi " << acos(kap22) / M_PI * 180 << endl;
			return false;
		}
	}
	else if ((y2 < 0) || (y2 > 0 (((x < x2) && (x2 < x1)) && ((y < y2) && (y2 < y1))))) {
		if (kap1 > 180) {
			cout << "OBchei ygol " << kap1 << endl;
			cout << "Pervei ygol with Pi " << acos(kap12) / M_PI * 180 << endl;
			cout << "Pervei ygol no Pi " << acos(kap12) << endl;
			return true;
		}
		else {
			cout << "OBchei ygol " << kap1 << endl;
			cout << "Pervei ygol with Pi " << acos(kap12) / M_PI * 180 << endl;
			cout << "Vtor ygol with Pi " << acos(kap22) / M_PI * 180 << endl;
			return false;
		}
	}
}







int main() {
	vector<vector<double>> stack = { };
	vector<double> stack_X;
	vector<double> stack_Y;
	int N = 0;
	cout << "Vvedite skolko tochek bydet" << endl;
	cin >> N;
	if (N <= 2) {
		cout << "TYPETCA, dymai lychshe" << endl;
		return -100;
	}
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
		stack_X1.push_back(stack_X[i] - stack_X[0]);
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
		if (tmp != 0)
		{
			stack_Y1[i] = atan(stack_Y1[i] / tmp) * 180 / M_PI; // Чтобы было в градусах
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
	// 2 -10
	// 1. осортировать относительно против часовой стрелки через
	// векторное произведение, если >0, то первый множитель идет 
	// раньше второго множителя, если <0, то первый множитель идет
	// после второго множителя.
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if ((stack_Y1[j] - stack_Y1[i]) < 0) {
				swap(stack_X1[i], stack_X1[j]);
				swap(stack_Y1[i], stack_Y1[j]);
				swap(stack_X[i], stack_X[j]);
				swap(stack_Y[i], stack_Y[j]);
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
	stack.push_back({ stack_X[0], stack_Y[0] });
	stack.push_back({ stack_X[1], stack_Y[1] });
	stack.push_back({ stack_X[2], stack_Y[2] });

	cout << endl;
	cout << endl;
	for (int i = 0; i < stack.size(); i++) {
		cout << "(" << stack[i][0] << "; " << stack[i][1] << ")";
		cout << endl;
	}
	int cian = 2;
	int step = 1;
	int post = 0;
	while ((cian + step) < stack_X.size()) {
		if (obolochka(stack_X[post] - stack_X[0], stack_Y[post] - stack_Y[0], stack_X[cian] - stack_X[0], stack_Y[cian] - stack_Y[0], stack_X[cian + step] - stack_X[0], stack_Y[cian + step] - stack_Y[0])) {
			post = cian;
			if ((stack[stack.size() - 1][0] == stack_X[cian + step]) && (stack[stack.size() - 1][1] == stack_Y[cian + step])) {
				cout << "Dobavki ne bydet" << endl;
			}
			else {
				stack.push_back({ stack_X[cian + step], stack_Y[cian + step] });
				cout << post << endl;;
				cout << "proverka_dobavka: " << stack[stack.size() - 1][0] << "; " << stack[stack.size() - 1][1] << endl;
				cout << endl;
			}

			cian = cian + step;
			if (step > 1) {
				step = 1;
			}
		}
		else {
			stack.push_back({ stack_X[cian + step], stack_Y[cian + step] });
			cout << "provereyam so svazkoi " << stack[stack.size() - 1][0] << "; " << stack[stack.size() - 1][1] << endl;
			stack.pop_back();
			cout << "proverka_ybavka: " << stack[stack.size() - 1][0] << "; " << stack[stack.size() - 1][1] << endl;
			stack.pop_back();
			if (cian > 1) {
				cian--;
			}
			cout << "cian = " << cian << endl;
			cout << "step = " << step << endl;
			cout << "Promezhytok: " << endl;
			cout << endl;
			for (int i = 0; i < stack.size(); i++) {
				cout << "(" << stack[i][0] << "; " << stack[i][1] << ")";
				cout << endl;
			}
			step++;
			cout << endl;
		}
	}


	cout << "Itog: " << endl;
	cout << endl;
	for (int i = 0; i < stack.size(); i++) {
		cout << "(" << stack[i][0] << "; " << stack[i][1] << ")";
		cout << endl;
	}


	return 0;
}