#include"HT.h"
#include <iostream>
using namespace std;

const int TABLE_SIZE1 = 100; 


int main()
{
    ifstream fin;
    vector<string> text = Read_File(fin);
    HashTable hashTable(TABLE_SIZE1);

    for (int i = 1; i < text.size(); ++i)
        hashTable.insert(text[i]);

    hashTable.Output_File();

    return 0;
}