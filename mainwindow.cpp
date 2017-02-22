#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "archer.h"
#include "horseman.h"
#include "infantryman.h"
#include "swordman.h"

#include "creategamecommand.h"
#include "movegamecommand.h"
#include "opengamecommand.h"
#include "savegamecommand.h"

#include "chainbase.h"

#include <functional>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->listWidget->model(), SIGNAL(rowsInserted(QModelIndex,int,int)),
            ui->listWidget, SLOT(scrollToBottom()));

    ui->comboBox->addItem("Мост-Прототип",0);
    patterns.push_back(&MainWindow::prototype);

    ui->comboBox->addItem("Комманда",1);
    patterns.push_back(&MainWindow::command);

    ui->comboBox->addItem("Цепочка",2);
    patterns.push_back(&MainWindow::chain);

    ui->comboBox->addItem("Компоновщик",3);
    patterns.push_back(&MainWindow::composite);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Start_clicked()
{
    int data = ui->comboBox->currentData().toInt();
    if(data<patterns.size()){
        (this->*(patterns[data]))();
    }
}

void MainWindow::command()
{
    /*Паттерн Комманда */
      UI_Bridge adapter(ui->lineEdit,ui->listWidget);
      Game game(&adapter);
      QVector<Command*> v;
      v.push_back(new CreateGameCommand(&game));
      v.push_back(new OpenGameCommand(&game));
      v.push_back(new SaveGameCommand(&game));
      v.push_back(new MoveGameCommand(&game));
      for(auto command : v ){
          command->execute();
      }
      for(auto cd : v){
          delete cd;
      }
    /*-----------------------------------------*/
}

void MainWindow::prototype()
{
    /*Паттерн Мост Logger LoggerImpl LogUI */
    /*Паттерн Прототип Warrior...*/
        auto logger= LogUI(ui->listWidget);
        QVector<Warrior*> qv;
        qv.push_back(Warrior::createWarrior(Infantryman_ID));
        logger.log("Infantryman");
        qv.push_back(Warrior::createWarrior(Archer_ID));
        logger.log(QString("Archer"));
        qv.push_back(Warrior::createWarrior(Horseman_ID));
        logger.log(QString("Horseman"));
        qv.push_back(Warrior::createWarrior(Swordman_ID));
        logger.log(QString("Swordman"));
        for(auto cd : qv){
            delete cd;
        }
        /*-----------------------------------------*/
}

void MainWindow::chain()
{
    /*Паттерн Цепочка обязанностей */
    UI_Bridge adapter(ui->lineEdit,ui->listWidget);
    srand(time(0));
    Handler1 root(&adapter);
    Handler2 two(&adapter);
    Handler3 three(&adapter);
    root.add(&two);
    root.add(&three);
    three.setNext(&root);
    for(int i=0;i<10;++i){
        root.handler(i);
    }
    /*------------------------*/
}

void MainWindow::composite()
{
    /*Паттерн Компановщик*/
    CompositeUnit* army = new CompositeUnit;
        for( int i=0;i<4;++i){
            army->addUnit(createLegion());
        }
    ui->listWidget->addItem("army Streanght: ");
    ui->listWidget->addItem(QString::number(army->getStreanght()));
    delete army;
    /*-----------------------*/
}

CompositeUnit *createLegion()
{
    CompositeUnit* legion = new CompositeUnit;
    for(int i = 0;i<1200;++i){
        legion->addUnit(new Archer);
    }
    for(int i = 0;i<3000;++i){
        legion->addUnit(new Horseman);
    }
    for(int i = 0;i<1000;++i){
        legion->addUnit(new Infantryman);
    }
    for(int i = 0;i<2000;++i){
        legion->addUnit(new Swordman);
    }
    return legion;
}
