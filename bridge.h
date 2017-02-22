#ifndef ADAPTER_H
#define ADAPTER_H
#include <QString>

class Bridge
{
public:
    virtual ~Bridge();
    virtual QString getInput()=0;
};

#endif // ADAPTER_H
