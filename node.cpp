#include "node.h"

template<class T>
node<T>::node(node<T>* l, node<T>* r):lnext(l),rnext(r){
	this->weight=l->getWeight()+r->getWeight();
    this->data=0;
}
template<class T>
node<T>::node(T s, int _weight):lnext(nullptr),rnext(nullptr){
    this->data=s;
	this->weight=_weight;
}
template<class T>
node<T>::node():lnext(nullptr),rnext(nullptr){
    this->data=0;
	this->weight=0;
}
template<class T>
node<T>::~node(){
	
}
template<class T>
node<T>* node<T>::getLnextNode() const{
	return this->lnext;
}
template<class T>
node<T>* node<T>::getRnextNode() const{
	return this->rnext;
}
template<class T>
void node<T>::setLNext(node<T>* n){
	this->lnext=n;
}
template<class T>
void node<T>::setRNext(node<T>* n){
	this->rnext=n;
}

template<class T>
void node<T>::setData(T* s){
    this->data=(*s);
}

template<class T>
int node<T>::getWeight()const{
	return this->weight;
}
template<class T>
T node<T>::getChar()const{
    return this->data;
}
