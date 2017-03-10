#ifndef FINDALGORITHMS_H
#define FINDALGORITHMS_H
#include "node.h"
#include "node.cpp"



template<class T>
class TreeT{

    std::list<node<T> >     _tree;
public:
    TreeT();
    void insert(const node<T>& n);
    void remove(const int& key);
    void find(const int& key);
};


#endif // FINDALGORITHMS_H
