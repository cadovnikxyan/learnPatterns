#include "pyrun.h"

#include <QString>
#include <QStringList>
#include <QDir>
#include <QFileInfo>
#include <QDebug>


PyRun::PyRun(QString execFile,UI_Bridge* ui)
{
    pr= new QProcess;
    QObject::connect(pr,&QProcess::readyReadStandardOutput,[&]{
        ui->output(pr->readAllStandardOutput());
        qDebug()<<"python  "<<pr->readAllStandardOutput();
    });
    pr->startDetached("python3.5",QStringList("PyTest.py"));


}

PyRun::~PyRun()
{
    qDebug()<<"PyRun destructor";
    delete pr;
}

PyObject* PyRun::importModule()
{

}

PyObject *PyRun::callFunction()
{


}



QString PyRun::ObjectToString()
{

}

