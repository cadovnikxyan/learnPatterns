#include "composite.h"



CompositeUnit *Unit::getComposite()
{
    return nullptr;
}

void CompositeUnit::addUnit(Unit *p)
{
    c.push_back(p);
}

CompositeUnit *CompositeUnit::getComposite()
{
    return this;
}

int CompositeUnit::getStreanght()
{
    int total=0;
    if(c.size()==0){
        return -1;
    }
    for(auto u : c){
        if(u->getComposite()!=0){
            total+=u->getComposite()->getStreanght();
        }else{
            total+=u->getStreanght();
        }
    }
    return total;
}

CompositeUnit::~CompositeUnit()
{
    for(auto u : c){
        delete u;
    }
}

