#ifndef UIADAPTER_H
#define UIADAPTER_H
#include "bridge.h"
#include <QLineEdit>
#include <QListWidget>
class UI_Bridge: public Bridge
{
public:
    UI_Bridge(QLineEdit* input, QListWidget *output);
    ~UI_Bridge();
    QString getInput();
    void output(const QString& str);
private:
    QLineEdit* lineEdit;
    QListWidget* listWidget;

};

#endif // UIADAPTER_H
