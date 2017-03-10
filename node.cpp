#include "node.h"

template<class T>
Node<T>::Node(Node<T>* l, Node<T>* r):lnext(l),rnext(r)
  ,height(l->getHeight()+r->getHeight()),data(0)
{

}
template<class T>
Node<T>::Node(T s, int _height):lnext(nullptr),rnext(nullptr)
  ,data(s),height(_height)
{

}

template<class T>
Node<T>::Node(T s, int _height, int _key):lnext(nullptr),rnext(nullptr)
  ,height(_height),key(key)
{

}


template<class T>
Node<T>::Node():lnext(nullptr),rnext(nullptr)
  ,data(0),height(0)
{

}
template<class T>
Node<T>::~Node(){
	
}
template<class T>
Node<T>* Node<T>::getLnextNode() const{
	return this->lnext;
}
template<class T>
Node<T>* Node<T>::getRnextNode() const{
	return this->rnext;
}
template<class T>
void Node<T>::setLNext(Node<T>* n){
	this->lnext=n;
}
template<class T>
void Node<T>::setRNext(Node<T>* n){
	this->rnext=n;
}

template<class T>
void Node<T>::setData(T* s){
    this->data=(*s);
}

template<class T>
void Node<T>::setHeight(int h)
{
    this->height= h;
}

template<class T>
int Node<T>::getHeight()const{
    return this->height;
}
template<class T>
T Node<T>::getData()const{
    return this->data;
}
