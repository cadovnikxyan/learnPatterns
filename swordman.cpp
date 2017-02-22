#include "swordman.h"

Warrior *Swordman::clone()
{
    return new Swordman(*this);
}

void Swordman::info()
{

}

int Swordman::getStreanght()
{
    return 4;
}

Swordman::~Swordman()
{

}

Swordman::Swordman()
{

}

Swordman::Swordman(Dimmy)
{
    Warrior::addPrototype(Swordman_ID,this);
}
