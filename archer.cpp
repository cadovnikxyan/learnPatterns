#include "archer.h"

Warrior *Archer::clone()
{
    return new Archer(*this);
}

void Archer::info()
{

}

Archer::~Archer()
{
}

int Archer::getAttack() const
{
    return attack;
}

void Archer::setAttack(int value)
{
    attack = value;
}

Archer::Archer(int at):attack(at)
{

}

Archer::Archer(Dimmy)
{
    Warrior::addPrototype(Archer_ID,this);
}
Archer Archer::prototype = Archer( Dimmy());
