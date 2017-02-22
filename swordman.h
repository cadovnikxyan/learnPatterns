#ifndef SWORDMAN_H
#define SWORDMAN_H
#include "warrior.h"

class Swordman : public Warrior,public Unit
{
public:
    Warrior* clone();
    void info();
    virtual int getStreanght();
    ~Swordman();
    Swordman();
private:
    Swordman(Dimmy);
    static Swordman prototype;

};

#endif // SWORDMAN_H
