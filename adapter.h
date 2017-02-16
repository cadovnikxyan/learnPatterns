#ifndef ADAPTER_H
#define ADAPTER_H
#include <QString>

class Adapter
{
public:
    virtual ~Adapter();
    virtual QString getInput()=0;
};

#endif // ADAPTER_H
