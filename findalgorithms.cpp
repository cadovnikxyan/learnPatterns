#include "findalgorithms.h"
#include <QDebug>


template<class T>
BinaryTree<T>::BinaryTree(Node<T> *root_):root(root){

}


template<class T>
Node<T>* BinaryTree<T>::insertAVL(Node<T> *n,T data)
{
    if(n==nullptr){
        auto node =new Node<T>(data);/*костыль  конструктор Node<T> для root, key неопределен*/
        tree.push_back(node);
        return node;
    }
    if(data < n->getData()){
       auto lnode = n->getLnextNode();
       lnode = insertAVL(n->getLnextNode(),data);
       n->setLNext(lnode);
    }else{
       auto rnode = n->getRnextNode();
       rnode = insertAVL(n->getRnextNode(),data);
       n->setRNext(rnode);
    }
    return balance(n);
}


template<class T>
Node<T>* BinaryTree<T>::insert(Node<T> *n,T data)
{
    if(n==nullptr){
        auto node =new Node<T>(data);
        tree.push_back(node);
        return node;
    }
    if(data < n->getData()){
       auto lnode = n->getLnextNode();
       lnode = insert(n->getLnextNode(),data);
    }else{
       auto rnode = n->getRnextNode();
       rnode = insert(n->getRnextNode(),data);
    }
    return n;
}

template<class T>
Node<T>* BinaryTree<T>::remove(Node<T>* n, int key)
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
Node<T> *BinaryTree<T>::find(Node<T>* n,T key)
{
    if(n==nullptr){
        return nullptr;
    }
    if(n->getData() == key){
        return n;
    }else if(key > n->getData()){
        return find(n->getRnextNode(),key);
    }else{
        return find(n->getLnextNode(),key);
    }
}


template<class T>
bool BinaryTree<T>::isBST()
{
    static Node<T>* parent = nullptr;
    if(root!=nullptr){
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
bool BinaryTree<T>::isBST(Node<T>* root)
{
    static Node<T>* parent = nullptr;
    if(root!=nullptr){
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
size_t BinaryTree<T>::getLenght()
{
    return tree.size();
}

template<class T>
QStringList BinaryTree<T>::toString(Node<T> *n)
{
    QString str;
    QStringList list;
    if(n!=nullptr && n->getData()!=0){
        str="\t\t" + QString::number(n->getData());
        list.append(str);
    } else{
        return list;
    }
    if(n->getLnextNode()!= nullptr ){
        str=""+QString::number(n->getLnextNode()->getData());
        list.append(str);
    }
    if(n->getRnextNode()!= nullptr){
        str="\t\t\t\t"+QString::number(n->getRnextNode()->getData());
        list.append(str);
    }

     return list;
}

template<class T>
int BinaryTree<T>::balanceFactor(Node<T> *n)
{
    return height(n->getRnextNode())- height(n->getLnextNode());
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

    auto lnode = n->getLnextNode();
    lnode = q->getRnextNode();

    auto rnode = q->getRnextNode();
    rnode = n;

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
            auto rnode = n->getRnextNode();
            rnode = rotateRight(n->getRnextNode());
        }
        return rotateLeft(n);
    }
    if(balanceFactor(n)==-2){
        if(balanceFactor(n->getLnextNode())>0){
           auto lnode = n->getLnextNode();
           lnode = rotateLeft(n->getLnextNode());
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
    auto rnode = n->getRnextNode();
    rnode = q->getLnextNode();
    auto lnode = q->getLnextNode();
    lnode =n;
    fixHeight(q);
    fixHeight(n);
    return q;
}
