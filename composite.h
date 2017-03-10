#ifndef COMPOSITE_H
#define COMPOSITE_H
#include <QVector>
class CompositeUnit;
class Unit
{
public:
    virtual int getStreanght()=0;
    virtual CompositeUnit* getComposite();
    virtual ~Unit();
};

class CompositeUnit:public Unit{
public:
    void addUnit(Unit* p);
    CompositeUnit* getComposite();
    int getStreanght();
    ~CompositeUnit();
private:
    QVector<Unit*> c;
};


#endif // COMPOSITE_H
