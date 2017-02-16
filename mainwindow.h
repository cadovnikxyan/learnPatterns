#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "warrior.h"
#include "game.h"
#include "command.h"

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
    void on_OK_clicked();

    void on_Game_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
