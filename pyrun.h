#ifndef PYRUN_H
#define PYRUN_H

#include <boost/python.hpp>
#include "ui_bridge.h"
#include <QString>
#include <QProcess>
class PyRun
{
public:
    PyRun(QString, UI_Bridge*);
    ~PyRun();


private:
    QProcess* pr;
    std::wstring execFile;
    std::wstring pythonPath;
    PyObject* importModule();
    PyObject* callFunction();
    QString ObjectToString();
};

#endif // PYRUN_H
