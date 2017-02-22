#ifndef HORSEMAN_H
#define HORSEMAN_H
#include "warrior.h"

class Horseman : public Warrior,public Unit
{
public:
    Warrior* clone();
    void info();
    virtual int getStreanght();
    Horseman();
    ~Horseman();
private:
    Horseman(Dimmy);
    static Horseman prototype;

};

#endif // HORSEMAN_H
