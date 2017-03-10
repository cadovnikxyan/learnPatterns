#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<class T>
class node
{
		
    node<T>*    lnext;
    node<T>*    rnext;
    T           data;
    int         weight;
	
	public:		
        node(node<T>* l,node<T>* r);
        node(T s, int _weight);
		node();
	   ~node();		
		
        node<T>*    getLnextNode() const;
        node<T>*    getRnextNode() const;
        int         getWeight()const;
        T           getChar()const;
		
        void        setLNext(node<T>* n);
        void        setRNext(node<T>* n);
        void        setData(T* s);


};

#endif
