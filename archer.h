#ifndef ARCHER_H
#define ARCHER_H
#include "warrior.h"

class Archer : public Warrior,public Unit
{
public:
    Warrior* clone();
    void info();
    virtual int getStreanght();
    ~Archer();
    Archer();

private:
    Archer(Dimmy);
    static Archer prototype;

};

#endif // ARCHER_H
