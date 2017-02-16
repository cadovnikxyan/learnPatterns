#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "archer.h"
#include "creategamecommand.h"
#include "movegamecommand.h"
#include "opengamecommand.h"
#include "savegamecommand.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OK_clicked()
{
    /*Паттерн Мост Logger LoggerImpl LogUI */
    /*Паттерн Прототип Warrior...*/
    auto logger= LogUI(ui->listWidget);
    QVector<Warrior*> qv;
    qv.push_back(Warrior::createWarrior(Infantryman_ID));
    logger.log("Infantryman");
    auto arch= new Archer(10);
    qv.push_back(arch);
    arch->clone();
    logger.log(QString::number(arch->getAttack()));
    qv.push_back(Warrior::createWarrior(Archer_ID));
    logger.log(QString("Archer")+ QString::number(dynamic_cast<Archer*>(qv.last())->getAttack()));
    qv.push_back(Warrior::createWarrior(Horseman_ID));
    logger.log(QString("Horseman"));
    qv.push_back(Warrior::createWarrior(Swordman_ID));
    logger.log(QString("Swordman"));
    /*-----------------------------------------*/
}

void MainWindow::on_Game_clicked()
{
    UIAdapter adapter(ui->lineEdit,ui->listWidget);
    Game game(&adapter);
    QVector<Command*> v;
    v.push_back(new CreateGameCommand(&game));
    v.push_back(new OpenGameCommand(&game));
    v.push_back(new SaveGameCommand(&game));
    v.push_back(new MoveGameCommand(&game));
    for(auto command : v ){
        command->execute();
    }
}
