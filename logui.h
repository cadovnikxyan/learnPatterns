#ifndef LOGUI_H
#define LOGUI_H

#include "logger.h"
#include "ui_logger_impl.h"
#include <QString>
class LogUI : public Logger
{
public:
    LogUI(QListWidget *list);
    void log(const QString& str);

private:
    QString string;
    QListWidget *listWidget;

};

#endif // LOGUI_H
