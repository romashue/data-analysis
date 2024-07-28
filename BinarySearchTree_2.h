#pragma once
#include<iostream>
#include<stack>
#include<string>
using namespace std;
namespace asd
{
    struct Node
    {
        int mValue;
        Node* mLeft;
        Node* mRight;

        explicit Node(int value, Node* left = nullptr, Node* right = nullptr) : mValue(value),
                                                                                mLeft(left), mRight(right)
        {}
    };

    class BinarySearchTree
    {
    private:
        Node* mRoot;

    public:
        explicit BinarySearchTree(const string& strTree) : mRoot(nullptr)
        {
            string number;
            for (auto sym : strTree)
            {
                if (sym == '(' || sym == ')' || sym == ',')
                {
                    if (!number.empty())
                    {
                        this->insert(stoi(number));
                        number.clear();
                    }
                }
                else
                    number += sym;
            }
        }

        BinarySearchTree() : mRoot(nullptr) {}

        ~BinarySearchTree()
        {
            destroyTree();
        }

        //вставляем значение
        void insert(int value) //***
        {
            if (mRoot == nullptr)
                mRoot = new Node(value);
            else
                this->insert(value, mRoot);
        }

        //Центральный обход(обход узлов в отсортированном порядке)
        void inOrderPrint(Node* node)
        {
            if (node != nullptr)
            {
                this->inOrderPrint(node->mLeft);
                cout << node->mValue << " ";
                this->inOrderPrint(node->mRight);
            }
        }

        //Прямой порядок(корень, левое поддерево, правое)
        void preOrderPrint(Node* node)
        {
            if (node != nullptr)
            {
                cout << node->mValue << " ";
                this->preOrderPrint(node->mLeft);
                this->preOrderPrint(node->mRight);
            }
        }

        //Обратный порядок(левое, начиная с детей; правое, начиная с детей; корень)
        void postOrderPrint(Node* node)
        {
            if (node != nullptr)
            {
                this->postOrderPrint(node->mLeft);
                this->postOrderPrint(node->mRight);
                cout << node->mValue << " ";
            }
        }

        void iterativePreOrderPrint(Node* node)
        {
            stack<Node*> nodeStack;
            nodeStack.push(node);
            Node* tmp;
            while (!nodeStack.empty())
            {
                tmp = nodeStack.top();
                cout << tmp->mValue << " ";
                nodeStack.pop();

                if (tmp->mRight)
                    nodeStack.push(tmp->mRight);
                if (tmp->mLeft)
                    nodeStack.push(tmp->mLeft);
            }
        }

        Node* getRoot()
        {
            return mRoot;
        }

        Node* find(Node* node, int value) //***
        {
            if ((node == nullptr) || (node->mValue == value))
                return node;
            if (value < node->mValue)
                return find(node->mLeft, value);
            else
                return find(node->mRight, value);
        }

        int GetVertex(Node* node) 
        {
            return node->mValue;
        }

        Node* findMin(Node* node)
        {
            if (node->mLeft == nullptr)
                return node;
            else
                return findMin(node->mLeft);
        }
        Node* add(Node* node, int value) {
            if (value < node->mValue)
            {
                if (node->mLeft == nullptr)
                {
                    node->mLeft = new Node(value);
                    return node;
                }
                else
                {
                    this->insert(value, node->mLeft);
                    return node;
                }
            }
            else
            {
                if (node->mRight == nullptr) {
                    node->mRight = new Node(value);
                    return node;
                }
                else {
                    this->insert(value, node->mRight);
                    return node;
                }
            }
        }

        Node* erase(Node* root, int value)
        {
            if (root == nullptr)
                return root;

            //рекурсивно продвигаемся к элементу, который нужно удалить
            if (value < root->mValue)
            {
                root->mLeft = erase(root->mLeft, value);
                return root;
            }
            else if (value > root->mValue)
            {
                root->mRight = erase(root->mRight, value);
                return root;
            }

            //если нет хотя бы одного потомка
            if (root->mLeft == nullptr)
            {
                Node* tmp = root->mRight;
                delete root;
                return tmp;
            }
            else if (root->mRight == nullptr)
            {
                Node* tmp = root->mLeft;
                delete root;
                return tmp;
            }
            else //если оба потомка есть
            {
                Node* parent = root;
                Node* child = root->mRight;
                while (child->mLeft != nullptr)
                {
                    parent = child;
                    child = child->mLeft;
                }
                if (parent != root)
                    parent->mLeft = child->mRight;
                else
                    parent->mRight = child->mRight;

                root->mValue = child->mValue;
                delete child;
                return root;
            }
        }

        void printTree(Node* root)
        {
            if (root == nullptr)
            {
                return;
            }
            cout << root->mValue <<endl;
            printSubtree(root, "");
            cout << endl;
        }

    private:
        //вставляем значение, начиная с некоторого узла
        void insert(int value, Node* node)
        {
            if (value < node->mValue)
            {
                if (node->mLeft == nullptr)
                    node->mLeft = new Node(value);
                else
                    this->insert(value, node->mLeft);
            }
            else
            {
                if (node->mRight == nullptr)
                    node->mRight = new Node(value);
                else
                    this->insert(value, node->mRight);
            }
        }

        void destroyTree()
        {
            destroySubTree(mRoot);
            mRoot = nullptr;
        }

        void destroySubTree(Node* node)
        {
            if (node != nullptr)
            {
                destroySubTree(node->mLeft);
                destroySubTree(node->mRight);
                delete node;
            }
        }

        void printSubtree(Node* root, const string& prefix)
        {
            if (root == nullptr)
            {
                return;
            }

            bool hasLeft = (root->mLeft != nullptr);
            bool hasRight = (root->mRight != nullptr);

            if (!hasLeft && !hasRight)
            {
                return;
            }

            cout << prefix;
            cout << ((hasLeft  && hasRight) ? "|-- " : "");
            cout << ((!hasLeft && hasRight) ? "|__ " : "");

            if (hasRight)
            {
                bool printStrand = (hasLeft && hasRight && (root->mRight->mRight != nullptr || root->mRight->mLeft != nullptr));
                string newPrefix = prefix + (printStrand ? "|   " : "    ");
                cout << root->mRight->mValue << endl;
                printSubtree(root->mRight, newPrefix);
            }

            if (hasLeft)
            {
                cout << (hasRight ? prefix : "") << "|__ " << root->mLeft->mValue << endl;
                printSubtree(root->mLeft, prefix + "    ");
            }
        }
    };
}
