#ifndef ARCHER_H
#define ARCHER_H
#include "warrior.h"

class Archer : public Warrior
{
public:
    Warrior* clone();
    void info();
    ~Archer();
    int attack=0;
    int getAttack() const;
    void setAttack(int value);
    Archer(int at);

private:
    Archer(Dimmy);
    static Archer prototype;

};

#endif // ARCHER_H
