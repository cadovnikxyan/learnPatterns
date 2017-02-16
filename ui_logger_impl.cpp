#include "ui_logger_impl.h"
#include <QDebug>
UI_Logger_Impl::UI_Logger_Impl(QListWidget *list):listWidget(list)
{

}

void UI_Logger_Impl::log(const QString &str)
{
    listWidget->addItem(str);
}

