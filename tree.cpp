#include "tree.h"



tree::tree(map<char,int>& _dic){
	
    for(auto it= _dic.begin();it!= _dic.end();++it){
        _tree.push_back(new Node<char>(it->first,it->second));
	}
		createTree(_tree);
}

tree::tree(string* str){
	
    for(auto its=str->begin();its!=str->end();++its){
            dic[*its]++;
    }
    for(auto it : dic){
        _tree.push_back(new Node<char>(it.first,it.second));
    }
	createTree(_tree);
}
tree::tree(string&& str){


    for(auto its=str.begin();its!=str.end();++its){
            dic[*its]++;
    }
    for(auto it : dic){
        _tree.push_back(new Node<char>(it.first,it.second));
    }
    createTree(_tree);
}
tree::~tree(){
	delete root;
}


void tree::printTree(){
        for(auto itc : tcode){
            cout<<itc.first<<endl;
            vector<bool> b=itc.second;
            for(auto i : b) cout<<i;
            cout<<endl;
		}
}

//struct MyCompare
//{
//    bool operator()(const Node<char>* l, const Node<char>* r) const{
//	 return l->getHeight() < r->getHeight();
//	}
//};

void tree::createTree(list<Node<char>*>& __tree ){
	
	while(__tree.size()!=1){
		
        __tree.sort();
		
        Node<char>* l=__tree.front();
		__tree.pop_front();

        Node<char>* r=__tree.front();
		__tree.pop_front();
		
        Node<char>* p= new Node<char>(l,r);				
		__tree.push_back(p);
						
	}		
		root=__tree.front();
		buildCodeTable(root);					
}

Node<char>* tree::getRoot()const{
	return this->root;
}


void tree::buildCodeTable(Node<char> *_root){
	
    if(_root->getLnextNode() != nullptr){
		code.push_back(0);
		buildCodeTable(_root->getLnextNode());
	}
    if(_root->getRnextNode() != nullptr){
		code.push_back(1);
		buildCodeTable(_root->getRnextNode());
	}
    if(_root->getLnextNode() == nullptr && _root->getRnextNode() == nullptr){
        tcode[_root->getData()]=code;
	}		
		code.pop_back();
}


map<char,vector<bool> >& tree::getCode(){

	return this->tcode;
}


void tree::writeTree(){
	ofstream t("output.tree",ios::out);
       auto it = tcode.begin();  /*map<char, vector<bool> >::iterator*/
			while(it!=tcode.end()){
				t<<it->first;
					string str;
					vector<bool> b=it->second;
                        for(auto i : b){
                            if(i){
								str+="1";
							}else{
								str+="0";
							}
						}
						t<<str<<endl;
						++it;
			}
}
void tree::writeTree(ofstream& stream){
        auto it= tcode.begin();  /*map<char, vector<bool> >::iterator*/
			while(it!=tcode.end()){
                stream<<it->first;
					string str;
					vector<bool> b=it->second;
                        for(auto i : b){
                            if(i){
								str+="1";
							}else{
								str+="0";
							}
						}
						stream<<str<<endl;
						++it;
			}
}




