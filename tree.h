#ifndef TREE_H
#define TREE_H
#include <map>
#include <list>
#include "node.h"
#include <fstream>

using namespace std;


class tree
{
	
    list<node<char>* >          _tree;
    node<char>*                 root;
    map<char,int>               dic;
    map<char, vector<bool> >    tcode;
    vector<bool>                code;
	
    void                        createDic(string* str);
    void                        createTree(list<node<char> * > &__tree );
    void                        buildCodeTable(node<char>* _root);
	
	public:
		
                                tree(map<char,int>& _dic);
                                tree(string* str);
                                tree(string &&str);
                               ~tree();
				
    void                        printTree();
    map<char,vector<bool> >&    getCode();
    void                        writeTree();
    void                        writeTree(ofstream& stream);
	
    node<char>*                 getRoot() const;
	
};

#endif
