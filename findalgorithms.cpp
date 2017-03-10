#include "findalgorithms.h"



template<class T>
void BinaryTree<T>::insert(const Node<T> &n)
{

}

template<class T>
void BinaryTree<T>::remove(const int &key)
{

}

template<class T>
void BinaryTree<T>::find(const int &key)
{

}


template<class T>
bool BinaryTree<T>::isBST(const Node<T> *root)
{
    static Node<T>* parent = nullptr;
    if(root){
        if(!isBST(root->getLnextNode())){
            return false;
        }
        if(parent!=nullptr && root->getData() <= parent->getData()){
            return false;
        }
        parent = root;
        return isBST(root->getRnextNode());
    }
    return true;
}

template<class T>
void BinaryTree<T>::sortTree(Node<T> *root)
{

}

template<class T>
int BinaryTree<T>::balanceFactor(Node<T> *n)
{
    return n->getRnextNode()->getHeight() - n->getLnextNode()->getHeight();
}

template<class T>
void BinaryTree<T>::fixHeight(Node<T> *n)
{
    int hl = height(n->getLnextNode());
    int hr = height(n->getRnextNode());
    n->setHeight((hl>hr?hl:hr)+1);
}

template<class T>
int BinaryTree<T>::height(Node<T> *n)
{
    return n?n->getHeight():0;
}

template<class T>
Node<T> *BinaryTree<T>::rotateRight(Node<T> *n)
{
    Node<T>* q = n->getLnextNode();
    n->getLnextNode()=q->getRnextNode();
    q->getRnextNode()=n;
    fixHeight(n);
    fixHeight(q);
    return q;
}

template<class T>
Node<T> *BinaryTree<T>::rotateLeft(Node<T> *n)
{
    Node<T>* q = n->getRnextNode();
    n->getRnextNode()=q->getLnextNode();
    q->getLnextNode()=n;
    fixHeight(n);
    fixHeight(q);
    return q;
}
