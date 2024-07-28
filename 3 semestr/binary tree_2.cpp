#include <iostream>
#include "BinarySearchTree_2.h"
#include<vector>

using namespace asd;
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    string strTree = "8(3(1,6(4,7)),10(,14(13,20)))";
    BinarySearchTree tree(strTree);
    cout << "Вершина: " << tree.GetVertex(tree.getRoot()) << endl;
    tree.printTree(tree.getRoot());
    cout << "-----------------------------" << endl;
    tree.erase(tree.getRoot(), 10);
    tree.printTree(tree.getRoot());
    cout << "-----------------------------" << endl;
    tree.add(tree.getRoot(), 45);
    tree.printTree(tree.getRoot());
    cout << "-----------------------------" << endl;
    tree.add(tree.getRoot(), 1);
    tree.add(tree.getRoot(), 7);
    tree.add(tree.getRoot(), 34);
    tree.add(tree.getRoot(), 8);
    tree.add(tree.getRoot(), 3);
    tree.add(tree.getRoot(), 2);
    tree.printTree(tree.getRoot());
    
    return 0;
}