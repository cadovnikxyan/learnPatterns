#ifndef INFANTRYMAN_H
#define INFANTRYMAN_H
#include "warrior.h"

class Infantryman : public Warrior,public Unit
{
public:
    Warrior* clone();
    void info();
    virtual int getStreanght();
    ~Infantryman();
    Infantryman();
private:
    Infantryman(Dimmy);
    static Infantryman prototype;

};

#endif // INFANTRYMAN_H
