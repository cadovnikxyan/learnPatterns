#ifndef FINDALGORITHMS_H
#define FINDALGORITHMS_H
#include "node.h"
#include "node.cpp"
#include <QString>


template<class T>
class BinaryTree{
    std::list<Node<T>* >     tree;
    Node<T>*                 root;
public:
    BinaryTree(Node<T>* root_);
    Node<T> *insertAVL(Node<T> *n, T data);
    Node<T> *insert(Node<T> *n, T data);
    Node<T> *remove(Node<T> *n, int key);
    Node<T>* find(Node<T> *n, T key);
    bool isBST();
    bool isBST(Node<T>* root);
    void sortTree(Node<T>* root);
    size_t getLenght();
    QStringList toString(Node<T>* n);

private:
    int balanceFactor(Node<T>* n);
    void fixHeight(Node<T>* n);
    int height(Node<T>* n);
    Node<T>* rotateLeft(Node<T>* n);
    Node<T>* rotateRight(Node<T>* n);
    Node<T>* balance(Node<T>* n);
    Node<T>* findMinimum(Node<T>* n);
    Node<T>* removeMinimum(Node<T>* n);
};


#endif // FINDALGORITHMS_H
