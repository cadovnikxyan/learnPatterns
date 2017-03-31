#include "ui_bridge.h"
#include <mutex>
#include <sstream>
#include <QThread>

UI_Bridge::UI_Bridge(QLineEdit *input, QListWidget* output):lineEdit(input),listWidget(output)
{

}

UI_Bridge::~UI_Bridge()
{

}

QString UI_Bridge::getInput()
{
    return lineEdit->text();
}

void UI_Bridge::output(const QString &str)
{
    static std::mutex m;
    std::lock_guard<std::mutex> lock(m);
    listWidget->addItem(/*QString( "0x%1" ).arg( (long long) QThread::currentThreadId(), 16 ) +" "+*/ str);
}
