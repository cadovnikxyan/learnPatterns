#ifndef TREE_H
#define TREE_H
#include <map>
#include <list>
#include "node.h"
#include <fstream>

using namespace std;


class tree
{
	
    list<Node<char>* >          _tree;
    Node<char>*                 root;
    map<char,int>               dic;
    map<char, vector<bool> >    tcode;
    vector<bool>                code;
	
    void                        createTree(list<Node<char> * > &__tree );
    void                        buildCodeTable(Node<char>* _root);
	
	public:
		
                                tree(map<char,int>& _dic);
                                tree(string* str);
                                tree(string&& str);
                               ~tree();
				
    void                        printTree();
    map<char,vector<bool> >&    getCode();
    void                        writeTree();
    void                        writeTree(ofstream &stream);
	
    Node<char>*                 getRoot() const;

	
};

#endif
