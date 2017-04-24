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
        Node(Node<T>* l,Node<T>* r):lnext(l),rnext(r),height(l->getHeight()+r->getHeight()),data(0){}

        Node(T s, int _height):lnext(nullptr),rnext(nullptr),data(s),height(_height){}

        Node(T s, int _height, int _key):lnext(nullptr),rnext(nullptr),height(_height),key(key){}

        Node(T s):lnext(nullptr),rnext(nullptr),height(1),data(s){key=data;}

        Node():lnext(nullptr),rnext(nullptr),data(0),height(0),key(0){}

       ~Node(){delete lnext; delete rnext;}
		
        Node<T>*    getLnextNode()       {return lnext;}
        Node<T>*    getRnextNode()       {return rnext;}
        int         getHeight()  const   {return height;}
        T           getKey()     const   {return key;}
        T           getData()    const   {return data;}
		
        void        setLNext(Node<T>* n){lnext=n;}
        void        setRNext(Node<T>* n){rnext=n;}
        void        setData(T* s){data=(*s);}
        void        setHeight(int h){height=h;}

        bool operator()(const Node<T>* l, const Node<T>* r) const{
         return l->getHeight() < r->getHeight();
        }
        bool operator<(const Node<T>& n) const{ return this->height < n.getHeight();}
        bool operator>(const Node<T>& n) const{ return this->height > n.getHeight();}
};

#endif
