#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

template<class T>
class Node
{
    private:
        Node<T>*    lnext;
        Node<T>*    rnext;
        T           data;
        int         height;
        int         key;
	
	public:		
        Node(Node<T>* l,Node<T>* r);
        Node(T s, int _height);
        Node(T s, int _height, int _key);
        Node();
       ~Node();
		
        Node<T>*    getLnextNode() const;
        Node<T>*    getRnextNode() const;
        int         getHeight()const;
        T           getData()const;
		
        void        setLNext(Node<T>* n);
        void        setRNext(Node<T>* n);
        void        setData(T* s);
        void        setHeight(int h);


};

#endif
