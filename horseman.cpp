#include "horseman.h"

Warrior *Horseman::clone()
{
    return new Horseman(*this);
}

void Horseman::info()
{

}

int Horseman::getStreanght()
{
    return 2;
}

Horseman::~Horseman()
{

}

Horseman::Horseman()
{

}

Horseman::Horseman(Dimmy)
{
    Warrior::addPrototype(Horseman_ID,this);
}

Horseman Horseman::prototype = Horseman( Dimmy());
