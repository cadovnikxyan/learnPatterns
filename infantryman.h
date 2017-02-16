#ifndef INFANTRYMAN_H
#define INFANTRYMAN_H
#include "warrior.h"

class Infantryman : public Warrior
{
public:
    Warrior* clone();
    void info();
    ~Infantryman();
private:
    Infantryman();
    Infantryman(Dimmy);
    static Infantryman prototype;

};

#endif // INFANTRYMAN_H
