#include "logui.h"

LogUI::LogUI(QListWidget *list):Logger(new UI_Logger_Impl(list)),listWidget(list)
{

}

void LogUI::log(const QString &str)
{
    pimpl->log(str);
}
