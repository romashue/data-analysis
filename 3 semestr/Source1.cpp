#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main() {
	ifstream in, in1, in2;
	ofstream out, out1, out2;
	int element1, element2 = 0;
	int count1, count2, count = 0;
	int size = 0;
	bool full_1, full_2 = true;
	bool flag = true;

	in.open("in.txt");
	out.open("out.txt");
	while (in >> element1) {
		out << element1 << " ";
		size++;
	}
	in.close();
	out.close();

	for (int i = 1; i < size; i = i * 2) {
		in.open("out.txt");
		out1.open("1.txt");
		out2.open("2.txt");
		count = 0;
		while (in >> element1) { // Древнюю Римскую империю поделили на пополам
			count++;
			if (flag) {
				out1 << element1 << " ";
			}
			else {
				out2 << element1 << " ";
			}
			if (count == i) {
				count = 0;
				flag = !flag;
			}
		}
		in.close();
		out1.close();
		out2.close();

		out.open("out.txt");
		in1.open("1.txt");
		in2.open("2.txt");
		// проверка на заполненность 
		if (in1 >> element1) { 
			full_1 = true;
		}
		else {
			full_1 = false;
		}
		if (in2 >> element2) {
			full_2 = true;
		}
		else {
			full_2 = false;
		}
		for (int j = 0; j < size; j = j + 2 * i) {
			count1 = 0;
			count2 = 0;
			while ((count1<i) && (full_1) && (count2 < i) && (full_2)) {
				if (element1 < element2) { // разбираем и сравниваем.
					out << element1 << " ";
					if (in1 >> element1) { 
						full_1 = true;
					}
					else {
						full_1 = false;
					}
					count1++;
				}
				else {
					out << element2 << " ";
					if (in2 >> element2) {
						full_2 = true;
					}
					else {
						full_2 = false;
					}
					count2++;
				}
			}
			while ((count1 < i) && full_1) { //добавляем остатки
				out << element1 << " ";
				if (in1 >> element1) {
					full_1 = true;
				}
				else {
					full_1 = false;
				}
				count1++;
			}
			while ((count2 < i) && full_2) {
				out << element2 << " ";
				if (in2 >> element2) {
					full_2 = true;
				}
				else {
					full_2 = false;
				}
				count2++;
			}

		}
		in1.close();
		in2.close();
		out.close();
		remove("1.txt");
		remove("2.txt");

	}



}