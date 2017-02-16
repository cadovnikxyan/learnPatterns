#include "uiadapter.h"

UIAdapter::UIAdapter(QLineEdit *input, QListWidget* output):lineEdit(input),listWidget(output)
{

}

UIAdapter::~UIAdapter()
{

}

QString UIAdapter::getInput()
{
    return lineEdit->text();
}

void UIAdapter::output(const QString &str)
{
    listWidget->addItem(str);
}
