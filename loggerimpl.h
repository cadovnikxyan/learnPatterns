#ifndef LOGGERIMPL_H
#define LOGGERIMPL_H
#include <QString>
#include <QListWidget>
class LoggerImpl
{
public:
    virtual ~LoggerImpl();
    virtual void log(const QString& str)=0;
//    virtual void logDebug(QString str)=0;
};

#endif // LOGGERIMPL_H
