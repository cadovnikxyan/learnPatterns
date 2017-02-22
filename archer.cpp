#include "archer.h"

Warrior *Archer::clone()
{
    return new Archer(*this);
}

void Archer::info()
{

}

int Archer::getStreanght()
{
 return 1;
}

Archer::~Archer()
{
}

Archer::Archer()
{

}



Archer::Archer(Dimmy)
{
    Warrior::addPrototype(Archer_ID,this);
}
Archer Archer::prototype = Archer( Dimmy());
