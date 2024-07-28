#pragma once
#include<string>
#include<fstream>
#include<list>
#include<vector>
using namespace std;
const int TABLE_SIZE = 100;

class HashTable
{
private:
    list<string>* table;
    ofstream fout;
    size_t mCap;

public:
    explicit HashTable(size_t cap) : mCap(cap)
    {
        table = new list<string>[mCap];
    }

    int Polynom_Hash(const string& slovo) //Hf(s1, ..., sn) = s0 * p^n-1 + s1 * p^n-2 + ... + s_n (обратный полином)  - полиномиальный хеш для строк 
    {
        int p = 31; // - константа
        int hash = 0;

        for (int i = 0; i < slovo.size(); ++i)
        {
            hash = (hash * p + static_cast<int>(slovo[i])) % TABLE_SIZE;
        }
        return hash;
    }
public:

    void insert(const string& slovo)
    {
        int index = this->Polynom_Hash(slovo);

        if (index < 0)
            throw out_of_range("Negative index!");

        bool wordExists = true;
        auto begin = table[index].begin();   
        while (begin != table[index].end())
        {
            if (*begin == slovo)
            {
                wordExists = false;
                *begin = slovo;
                break;
            }
            ++begin;
        }

        if (wordExists){
            table[index].push_back(slovo);
        }
    }

    void Output_File()
    {
        fout.open("text.txt");
        string temp;
        const int maxCountDigit = static_cast<int>(to_string(TABLE_SIZE).size());
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            temp = to_string(i);
            temp.resize(maxCountDigit);
            fout << temp << " " << '\t';
            for (const auto& element : table[i])
            {
                temp = element;
                temp.resize(15);
                fout << temp << '\t';
            }
            fout << endl;
        }
    }

    ~HashTable()
    {
        delete[] table;
    }


};

vector<string> Read_File(ifstream& fin)
{
    string slovo;
    vector<string> text;

    fin.open("input.txt");
    if (!fin.is_open())
        throw exception("File miss");
    else
    {
        while (fin >> slovo)
        {
            text.push_back(slovo);
        }
    }
    fin.close();

    return text;
}