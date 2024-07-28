#include<iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> stack;
	vector<int> stack_X;
	vector<int> stack_Y;
	int N = 0;
	cout << "Vvedite skolo tochek bydet" << endl;
	cin >> N;
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << "vvedite koordinati tochki nomer " << i+1 << endl;
		for (int j = 0; j < 2; j++) {
			if (j ==0)		{
				int a = 0;
				cin >> a;
				stack_X.push_back(a);
			}
			if (j == 1){
				int a = 0;
				cin >> a;
				stack_Y.push_back(a);
			}
		}
	}
	int min = stack_X[0];
	for (int i = 1; i < N; i++) {
		if (min > stack_X[i]) {
			swap(stack_X[i], stack_X[0]);
			swap(stack_Y[i], stack_Y[0]);
		}
	}
	for (int i = 1; i < N; i++) {
		if (min > stack_X[i]) {
		}
	}
	for (int i = 0; i < N; i++) {
		cout << "(" << stack_X[i] << ";" << stack_Y[i] << ")" << endl;
	}
	return 0;
}