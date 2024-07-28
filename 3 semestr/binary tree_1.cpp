#include <iostream>
#include "BinaryTree_1.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    string strTree = "8(3(1,6(4,7)),10(,14(13,)))";

    try
    {
        asd::BinaryTree tree(strTree);
        cout << "Центральный: "; 
        tree.inOrderPrint(tree.getRoot());
        cout << endl;

        cout << "Прямой: "; 
        tree.preOrderPrint(tree.getRoot());
        cout << endl;

        cout << "Прямой не рекурсивный: "; 
        tree.iterativePreOrderPrint(tree.getRoot());
        cout << endl;

        cout << "Концевой: "; 
        tree.postOrderPrint(tree.getRoot());
        cout << endl;
 
    }
    catch (const exception& ex) 
    { 
        cout << ex.what(); 
    }


    return 0;
}