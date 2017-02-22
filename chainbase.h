#ifndef CHAINBASE_H
#define CHAINBASE_H
#include <ctime>
#include "ui_bridge.h"

class ChainBase
{
    ChainBase* next;
public:
    ChainBase(UI_Bridge* adapter);
    void setNext(ChainBase* n);
    void add(ChainBase* n);
    virtual void handler(int i);
protected:
    UI_Bridge* ui;
};

class Handler1: public ChainBase{
    public:
        Handler1(UI_Bridge* adapter);
        void handler(int i);
};

class Handler2: public ChainBase{
    public:
        Handler2(UI_Bridge* adapter);
        void handler(int i);
};

class Handler3: public ChainBase{
    public:
        Handler3(UI_Bridge* adapter);
        void handler(int i);
};
#endif // CHAINBASE_H
