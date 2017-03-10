#ifndef FINDALGORITHMS_H
#define FINDALGORITHMS_H
#include "node.h"
#include "node.cpp"



template<class T>
class BinaryTree{

    std::list<Node<T> >     tree;
public:
    BinaryTree();
    void insert(const Node<T>& n);
    void remove(const int& key);
    void find(const int& key);
    bool isBST(const Node<T>* root);
    void sortTree(Node<T>* root);
private:
    int balanceFactor(Node<T>* n);
    void fixHeight(Node<T>* n);
    int height(Node<T>* n);
    Node<T>* rotateLeft(Node<T>* n);
    Node<T>* rotateRight(Node<T>* n);

};


#endif // FINDALGORITHMS_H
