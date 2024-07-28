#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int TABLE_SIZE = 100;  // ����� ����� ���-������� ��� ���������� ���������

class HashTable // ����� ��� ���-������� 
{
private:
    vector<string> table;
    int PolynomHash(const string& word) //Hf(s1, ..., sn) = s0 * p^n-1 + s1 * p^n-2 + ... + s_n (�������� �������)  - �������������� ��� ��� ����� 
    {
        int p = 31; // - ���������
        int hash = 0; 

        for (int i = 0; i < word.size(); ++i)
        {
            hash = (hash * p + static_cast<int>(word[i])) % TABLE_SIZE;
        }
        return hash;
    }
public:
    HashTable() 
    {
        table.resize(TABLE_SIZE, "");
    }

    void insert(const string& slovo) 
    {
        int ind = PolynomHash(slovo);

        while (!table[ind].empty()) {
            ind = (ind + 1) % TABLE_SIZE;
        }

        table[ind] = slovo;
    }

    void Write_To_Output_File(const string& filename)
    {
        ofstream outputFile(filename);

        if (outputFile.is_open()) {
            for (int i = 0; i < TABLE_SIZE; ++i) {
                outputFile << i << ": " << table[i] << endl;
            }
            outputFile.close();
        }
        else {
            cerr << "File error" << endl;
        }
    }
};