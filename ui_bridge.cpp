#include "ui_bridge.h"

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
    listWidget->addItem(str);
}
