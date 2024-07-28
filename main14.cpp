#include "HT_14.h"

int main() {
    HashTable hashTable;

    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "File error" << endl;
        return 1;
    }

    string word;
    while (inputFile >> word) 
    {
        hashTable.insert(word);
    }

    hashTable.Write_To_Output_File("text.txt");

    return 0;
}
