#ifndef UIADAPTER_H
#define UIADAPTER_H
#include "adapter.h"
#include <QLineEdit>
#include <QListWidget>
class UIAdapter: public Adapter
{
public:
    UIAdapter(QLineEdit* input, QListWidget *output);
    ~UIAdapter();
    QString getInput();
    void output(const QString& str);
private:
    QLineEdit* lineEdit;
    QListWidget* listWidget;

};

#endif // UIADAPTER_H
