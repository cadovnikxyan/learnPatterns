#ifndef LOGGER_H
#define LOGGER_H
#include<QString>
class LoggerImpl;
class Logger
{
public:
    Logger(LoggerImpl* p);
    virtual ~Logger();
    virtual  void log(const QString& str)=0;
protected:
    LoggerImpl* pimpl;
};

#endif // LOGGER_H
