#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int split(vector<int> &mas, int start, int end) { // cортировка от и до  
    int opora = mas[end];
    int index_opora = start;

    for (int i = start; i < end; i++) {
        cout << endl;
        cout << "Before_mas[i] = " << mas[i] << endl;
        if (mas[i] <= opora) {
            swap(mas[i], mas[index_opora]);
            index_opora++;
        }
    
        cout << "mas[i] = " << mas[i] << endl;
        cout << "mas[index_opora] = " << mas[i] << endl;
    }
    swap(mas[end], mas[index_opora]); // обратно впихиваем вправо
    cout << endl;
    cout << "opora = " << opora << endl;
    return index_opora;
   
}
void sortirovka(vector<int>& mas, int start, int end) {
    if (start >= end) {
        return;
    }
    for (int i = 0; i < mas.size(); i++) {
        cout << mas[i] << endl;
    }
    int opora = split(mas, start, end);
    sortirovka(mas, start, opora-1);
    sortirovka(mas, opora+1, end);
}



int main() {
    vector<int> mas = { 10, 5, 706, 23, 10, 9, 3, 97, 98 };
    sortirovka(mas, 0, mas.size()-1);
    for (int i = 0; i < mas.size(); i++) {
        cout << mas[i] << endl;
    }
    return 0;
}

