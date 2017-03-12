#include "findalgorithms.h"
#include <QDebug>


template<class T>
void BinaryTree<T>::insert(const Node<T> *n,T data, int key)
{
    if(!n){
        return new Node<T>(data,0,key);
    }
    if(key< n.getKey()){
        n->getLnextNode()=insert(n->getLnextNode(),data,key);
    }else{
        n->getRnextNode()=insert(n->getRnextNode(),data,key);
    }
    return balance(n);
}

template<class T>
void BinaryTree<T>::remove(Node<T>* n, int key)
{
    if(!n){
        return nullptr;
    }
    if(key < n->getKey()){
        n->getLnextNode() = remove(n->getLnextNode(),key);
    }else if(key > n->getKey()){
        n->getRnextNode() = remove(n->getRnextNode(),key);
    }else{
        Node<T>* l = n->getLnextNode();
        Node<T>* r = n->getRnextNode();
        delete n;
        if(!r){
            return l;
        }
        Node<T>* minimun = findMinimum(n);
        minimun->getRnextNode() = removeMinimum(r);
        minimun->getLnextNode() = l;
        return balance(minimun);
    }
    return balance(n);
}

template<class T>
void BinaryTree<T>::find(int key)
{

}


template<class T>
bool BinaryTree<T>::isBST(const Node<T> *root)
{
    static Node<T>* parent = nullptr;
    if(root!=nullptr){
        if(!isBST(root->getLnextNode())){
            return false;
        }
        if(parent!=nullptr && root->getData() <= parent->getData()){
            return false;
        }
        parent = const_cast<Node<T>*>(root);
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
Node<T> *BinaryTree<T>::balance(Node<T> *n)
{
    fixHeight(n);
    if(balanceFactor(n)==2){
        if(balanceFactor(n->getRnextNode())<0){
            n->getRnextNode()=rotateRight(n->getRnextNode());
        }
        return rotateLeft(n);
    }
    if(balanceFactor(n)==-2){
        if(balanceFactor(n->getLnextNode())>0){
            n->getLnextNode()=rotateLeft(n->getLnextNode());
        }
        return rotateRight(n);
    }
    return n;
}

template<class T>
Node<T> *BinaryTree<T>::findMinimum(Node<T> *n)
{
    return n->getLnextNode()?findMinimum(n->getLnextNode()):n;
}

template<class T>
Node<T> *BinaryTree<T>::removeMinimum(Node<T> *n)
{
    if(n->getLnextNode()==0){
        return n->getRnextNode();
    }
    n->getLnextNode() = removeMinimum(n->getLnextNode());
    return balance(n);
}

template<class T>
Node<T> *BinaryTree<T>::rotateLeft(Node<T> *n)
{
    Node<T>* q = n->getRnextNode();
    n->getRnextNode()=q->getLnextNode();
    q->getLnextNode()=n;
    fixHeight(q);
    fixHeight(n);
    return q;
}
