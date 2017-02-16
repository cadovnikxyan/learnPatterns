#ifndef ST_LOGGER_IMPL_H
#define ST_LOGGER_IMPL_H
#include "loggerimpl.h"

class UI_Logger_Impl : public LoggerImpl
{
public:
    UI_Logger_Impl(QListWidget* list);
    void log(const QString &str);
protected:
    QListWidget *listWidget;
};

#endif // ST_LOGGER_IMPL_H
