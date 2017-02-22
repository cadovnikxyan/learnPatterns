#include "templatemethod.h"

TemplateMethodBase::TemplateMethodBase(UI_Bridge* adapter):ui(adapter)
{

}

void TemplateMethodBase::a()
{
    ui->output("TemplateMethod A");
}

void TemplateMethodBase::b()
{
    ui->output("TemplateMethod B");
}

void TemplateMethodBase::c()
{
    ui->output("TemplateMethod C");
}

void TemplateMethodBase::execute()
{
    a();
    tm1();
    b();
    tm2();
    c();
}

TemplateMethodOne::TemplateMethodOne(UI_Bridge *adapter):TemplateMethodBase(adapter)
{

}

void TemplateMethodOne::tm1()
{
    ui->output("TemplateMethodOne tm1");
}

void TemplateMethodOne::tm2()
{
    ui->output("TemplateMethodOne tm2");
}

TemplateMethodTwo::TemplateMethodTwo(UI_Bridge *adapter):TemplateMethodBase(adapter)
{

}

void TemplateMethodTwo::tm1()
{
    ui->output("TemplateMethodTwo tm1");
}

void TemplateMethodTwo::tm2()
{
    ui->output("TemplateMethodTwo tm2");
}

TemplateMethodThree::TemplateMethodThree(UI_Bridge *adapter):TemplateMethodBase(adapter)
{

}

void TemplateMethodThree::tm1()
{
    ui->output("TemplateMethodThree tm1");
}

void TemplateMethodThree::tm2()
{
    ui->output("TemplateMethodThree tm2");
}
