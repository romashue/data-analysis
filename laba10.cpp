#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void sortirovka(vector<int> &mas, int index, int size) { // cортировка от и до

    if (size == index) { // если конец совпадает с начальным индексом
        return;
    }
    int mid = (size + index) / 2;
    sortirovka(mas, index, mid); // делим на 2 части, а после делаем рекурсию
    sortirovka(mas, mid+1, size);
    int i = index;
    int j = mid + 1;

    vector<int> tmp(mas.size() + 1, 0);
    for (int k = 0; k < size - index + 1; k++){
        if ((j > size) || ((i <= mid) && (mas[i] < mas[j]))){
            tmp[k] = mas[i];
            i++;
        }
        else{
            tmp[k] = mas[j];
            j++;
        }
    }
    for (int k = 0; k < size - index + 1; k++) {
        mas[index + k] = tmp[k];
        
    }
  
    for (int t = 0; t < mas.size(); t++) {
        cout << mas[t] << endl;
    }
    cout << endl;
}



int main() {
    vector<int> mas = { 10, 5, 706, 23, 10, 9, 3, 97, 98 };
    sortirovka(mas, 0, mas.size()-1);

    return 0;
}

