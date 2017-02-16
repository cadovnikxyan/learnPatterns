#include "horseman.h"

Warrior *Horseman::clone()
{
    return new Horseman(*this);
}

void Horseman::info()
{

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
