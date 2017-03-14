#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "warrior.h"
#include "game.h"
#include "command.h"
#include "huffmanalgorithm.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Start_clicked();

private:
    Ui::MainWindow *ui;
    void command();
    void prototype();
    void chain();
    void composite();
    void templateMethod();
    void decorator();
    void archive();
    void binaryTree();
    void threads();
    void singlton();
    void(MainWindow::*pattPtr)();
    QVector<void(MainWindow::*)()> patterns;

};
CompositeUnit* createLegion();
#endif // MAINWINDOW_H
