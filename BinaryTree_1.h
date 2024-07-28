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

    class BinaryTree
    {
    private:
        Node* mRoot;

    public:
        explicit BinaryTree(const string& strTree) : mRoot(nullptr)
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

        BinaryTree() : mRoot(nullptr) {}

        //вставляем значение
        void insert(int value)
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

        //Обратный порядок(левое, начиная с детей; правое, начиная с детей; корень) !Концевой!
        void postOrderPrint(Node* node)
        {
            if (node != nullptr)
            {
                this->postOrderPrint(node->mLeft);
                this->postOrderPrint(node->mRight);
                cout << node->mValue << " ";
            }
        }

        //Прямой порядок(корень, левое поддерево, правое) !не рекурсивный!
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
    private:
        //вставляем значение, начиная с некоторого узла
        void insert(int value, Node* node)
        {
            if (value == node->mValue)
            {
                throw logic_error("The tree contains a node with this value!");
            }

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

    };
}