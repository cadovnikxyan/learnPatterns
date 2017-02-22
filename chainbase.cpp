#include "chainbase.h"

ChainBase::ChainBase(UI_Bridge* adapter):ui(adapter)
{
    next=nullptr;
}

void ChainBase::setNext(ChainBase *n)
{
    next=n;
}

void ChainBase::add(ChainBase *n)
{
    if(next!=nullptr){
        next->add(n);
    }else{
        next=n;
    }
}

void ChainBase::handler(int i)
{
    next->handler(i);
}

Handler1::Handler1(UI_Bridge *adapter):ChainBase(adapter)
{

}

void Handler1::handler(int i)
{
    if(rand()%3){
        ui->output("H1 passed");
        ChainBase::handler(i);
    }else{
        ui->output("H1 hundled");
    }

}

Handler2::Handler2(UI_Bridge *adapter):ChainBase(adapter)
{

}

void Handler2::handler(int i)
{
    if(rand()%3){
        ui->output("H2 passed");
        ChainBase::handler(i);
    }else{
        ui->output("H2 hundled");
    }
}

Handler3::Handler3(UI_Bridge *adapter):ChainBase(adapter)
{

}

void Handler3::handler(int i)
{
    if(rand()%3){
        ui->output("H3 passed");
        ChainBase::handler(i);
    }else{
        ui->output("H3 hundled");
    }
}
