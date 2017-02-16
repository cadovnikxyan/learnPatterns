#ifndef SWORDMAN_H
#define SWORDMAN_H
#include "warrior.h"

class Swordman : public Warrior
{
public:
    Warrior* clone();
    void info();
    ~Swordman();
private:
    Swordman();
    Swordman(Dimmy);
    static Swordman prototype;

};

#endif // SWORDMAN_H
