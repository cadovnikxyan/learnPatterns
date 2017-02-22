#ifndef WARRIOR_H
#define WARRIOR_H
#include <map>
#include "logui.h"
#include "composite.h"
enum Warrior_ID {
    Infantryman_ID,
    Archer_ID,
    Horseman_ID,
    Swordman_ID
};

class Warrior;

typedef std::map<Warrior_ID, Warrior*> Registry;

Registry& getRegistry();

class Dimmy{};
class Warrior
{
public:
    virtual Warrior* clone()= 0;
    virtual void info() =0;
    virtual ~Warrior();
    static Warrior* createWarrior(Warrior_ID id);
protected:
    static void addPrototype (Warrior_ID id, Warrior* proto);
    static void removePrototype(Warrior_ID id);
};

#endif // WARRIOR_H
