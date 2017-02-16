#ifndef HORSEMAN_H
#define HORSEMAN_H
#include "warrior.h"

class Horseman : public Warrior
{
public:
    Warrior* clone();
    void info();
    ~Horseman();
private:
    Horseman();
    Horseman(Dimmy);
    static Horseman prototype;

};

#endif // HORSEMAN_H
