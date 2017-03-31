//#include "node.h"


//template<class T>
//Node<T>::Node(Node<T>* l, Node<T>* r):lnext(l),rnext(r)
//  ,height(l->getHeight()+r->getHeight()),data(0)
//{

//}
//template<class T>
//Node<T>::Node(T s, int _height):lnext(nullptr),rnext(nullptr)
//  ,data(s),height(_height)
//{

//}

//template<class T>
//Node<T>::Node(T s, int _height, int _key):lnext(nullptr),rnext(nullptr)
//  ,height(_height),key(key)
//{

//}
//template<class T>
//Node<T>::Node(T s):lnext(nullptr),rnext(nullptr),height(1),data(s)
//{
//    key=data;
//}


//template<class T>
//Node<T>::Node():lnext(nullptr),rnext(nullptr)
//  ,data(0),height(0),key(0)
//{

//}
//template<class T>
//Node<T>::~Node(){
//    delete lnext;
//    delete rnext;
//}
//template<class T>
//Node<T>* Node<T>::getLnextNode() {
//    return lnext;
//}
//template<class T>
//Node<T>* Node<T>::getRnextNode() {
//    return rnext;
//}
//template<class T>
//void Node<T>::setLNext(Node<T>* n){
//    lnext=n;
//}
//template<class T>
//void Node<T>::setRNext(Node<T>* n){
//    rnext=n;
//}

//template<class T>
//void Node<T>::setData(T* s){
//    data=(*s);
//}

//template<class T>
//void Node<T>::setHeight(int h)
//{
//    height= h;
//}

//template<class T>
//int Node<T>::getHeight()const{
//    return height;
//}
//template<class T>
//T Node<T>::getData()const{
//    return data;
//}

//template<class T>
//T Node<T>::getKey() const
//{
//    return getData();
//}
