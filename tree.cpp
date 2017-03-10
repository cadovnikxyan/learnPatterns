#include "tree.h"
#include "node.cpp"


tree::tree(map<char,int>& _dic){
	
    for(auto it= _dic.begin();it!= _dic.end();++it){
        _tree.push_back(new Node<char>(it->first,it->second));
	}
		createTree(_tree);
}

tree::tree(string* str){
	
    auto its=str->begin();
		for(;its!=str->end();++its){					
				dic[*its]++;				
		}	
    for(auto it= dic.begin();it!= dic.end();++it){
        _tree.push_back(new Node<char>(it->first,it->second));
	}
	createTree(_tree);
}
tree::tree(string&& str){

    auto its=str.begin();
        for(;its!=str.end();++its){
                dic[*its]++;
        }
    for(auto it= dic.begin();it!= dic.end();++it){
        _tree.push_back(new Node<char>(it->first,it->second));
    }
    createTree(_tree);
}
tree::~tree(){
	delete root;
}


void tree::printTree(){
        auto itc=tcode.begin();
		for(;itc!=tcode.end();++itc){
			cout<<itc->first<<endl;
			vector<bool> b=itc->second;
            for(auto i=0;i<b.size();++i){
				cout<<b[i];
			}
			cout<<endl;
		}
}

struct MyCompare
{
    bool operator()(const Node<char>* l, const Node<char>* r) const{
	 return l->getHeight() < r->getHeight();
	}
};

void tree::createTree(list<Node<char>*>& __tree ){
	
	while(__tree.size()!=1){
		
		__tree.sort(MyCompare());
		
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
		map<char, vector<bool> >::iterator it= tcode.begin();
			while(it!=tcode.end()){
				t<<it->first;
					string str;
					vector<bool> b=it->second;
                        for(auto i=0;i<b.size();++i){
							if(b[i]){
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
		map<char, vector<bool> >::iterator it= tcode.begin();
			while(it!=tcode.end()){
				stream<<it->first;
					string str;
					vector<bool> b=it->second;
                        for(auto i=0;i<b.size();++i){
							if(b[i]){
								str+="1";
							}else{
								str+="0";
							}
						}
						stream<<str<<endl;
						++it;
			}
}

void tree::createDic(string* str){
						
        auto it = str->begin();
		for(;it!=str->end();++it){					
				dic[*it]++;				
		}
				
}


