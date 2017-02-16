#include "infantryman.h"

Warrior *Infantryman::clone()
{
    return new Infantryman(*this);
}

void Infantryman::info()
{

}

Infantryman::~Infantryman()
{

}

Infantryman::Infantryman()
{

}

Infantryman::Infantryman(Dimmy)
{
    Warrior::addPrototype(Infantryman_ID,this);
}

Infantryman Infantryman::prototype = Infantryman( Dimmy());
