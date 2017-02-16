#include "warrior.h"


Warrior::~Warrior()
{

}

Warrior* Warrior::createWarrior(Warrior_ID id)
{
    Registry& r= getRegistry();
    if(r.find(id)!=r.end()){
       return r[id]->clone();
    }
    return 0;
}

void Warrior::addPrototype(Warrior_ID id, Warrior *proto)
{
    Registry& r = getRegistry();
    r[id]=proto;
}

void Warrior::removePrototype(Warrior_ID id)
{
    Registry& r = getRegistry();
    r.erase(r.find(id));
}

Registry &getRegistry()
{
    static Registry instance;
    return instance;

}
