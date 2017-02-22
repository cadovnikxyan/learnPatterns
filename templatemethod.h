#ifndef TEMPLATEMETHOD_H
#define TEMPLATEMETHOD_H
#include "ui_bridge.h"

class TemplateMethodBase
{
    void a();
    void b();
    void c();
    virtual void tm1()=0;
    virtual void tm2()=0;
protected:
    UI_Bridge* ui;
public:
    TemplateMethodBase(UI_Bridge* adapter);
    void execute();
};
class TemplateMethodOne : public TemplateMethodBase{

public:
    TemplateMethodOne(UI_Bridge* adapter);
    void tm1();
    void tm2();
};

class TemplateMethodTwo: public TemplateMethodBase{

public:
    TemplateMethodTwo(UI_Bridge* adapter);
    void tm1();
    void tm2();
};


class TemplateMethodThree: public TemplateMethodBase{

public:
    TemplateMethodThree(UI_Bridge* adapter);
    void tm1();
    void tm2();
};
#endif // TEMPLATEMETHOD_H
