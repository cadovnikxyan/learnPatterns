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

#include "templatemethod.h"

#include "findalgorithms.h"
#include "findalgorithms.cpp"

#include "singlton.h"

#include "threadspatterns.h"

#include <functional>
#include <utility>

#include <pyrun.h>

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

    ui->comboBox->addItem("Шаблонный метод",4);
    patterns.push_back(&MainWindow::templateMethod);

    ui->comboBox->addItem("Декоратор",5);
    patterns.push_back(&MainWindow::decorator);

    ui->comboBox->addItem("Хаффман",6);
    patterns.push_back(&MainWindow::archive);

    ui->comboBox->addItem("Бинарные деревья",7);
    patterns.push_back(&MainWindow::binaryTree);

    ui->comboBox->addItem("Потоки",8);
    patterns.push_back(&MainWindow::threads);

    ui->comboBox->addItem("Синглтон",9);
    patterns.push_back(&MainWindow::singlton);

    ui->comboBox->addItem("Питон",10);
    patterns.push_back(&MainWindow::python);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Start_clicked()
{
    int data = ui->comboBox->currentData().toInt();
    if(data==6){
        (this->*(patterns[data]))();
        return;
    }
    if(data<patterns.size()){
        std::thread tr(patterns[data],this);
        tr.detach();
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

void MainWindow::templateMethod()
{
    /*Паттерн Шаблонный метод*/
    UI_Bridge adapter(ui->lineEdit,ui->listWidget);

    TemplateMethodOne one(&adapter);
    TemplateMethodTwo two(&adapter);
    TemplateMethodThree three(&adapter);

    QVector<TemplateMethodBase*> v = {&one,&two,&three};
    for(auto t : v){
        t->execute();
    }
    /*------------------------*/
}

void MainWindow::decorator()
{

}

void MainWindow::archive()
{
    HuffmanAlgorithm* h = new HuffmanAlgorithm(0);
    h->exec();
    delete h;

}

template<class T>
void recusiveT(Node<T>* root,BinaryTree<T>* t, Ui::MainWindow *ui){
    if(root==nullptr){
        return;
    }
    auto lnode = root->getLnextNode();
    auto rnode = root->getRnextNode();

    ui->listWidget->addItems(t->toString(root));

    if(lnode!=nullptr){
        ui->listWidget->addItems(t->toString(lnode));
        recusiveT(lnode,t,ui);
    }
    if(rnode!=nullptr){
        ui->listWidget->addItems(t->toString(rnode));
        recusiveT(rnode,t,ui);
    }
}

void MainWindow::binaryTree()
{
    Node<int>* root= nullptr;
    BinaryTree<int>* t= new BinaryTree<int>(root);
    int keys[]= {15,10,20,8,12,16,25};
    for( auto key : keys){
       root = t->insertAVL(root,key);
    }
        ui->listWidget->addItem(QString("tree size = ")+ QString::number(t->getLenght()));
        auto lnode = root->getLnextNode();
        auto rnode = root->getRnextNode();
        std::swap(lnode,rnode);

    if(t->isBST(root)){
        ui->listWidget->addItem("true");
        auto k = t->find(root,25);
        if(k!=nullptr){
            ui->listWidget->addItem(QString("finded node with data = ")+ QString::number(k->getData()));
        }else{
            ui->listWidget->addItem("node is`t find");
        }
    }else{
        ui->listWidget->addItem("false");
    }

}

void MainWindow::threads()
{
    UI_Bridge adapter(ui->lineEdit,ui->listWidget);

    scheduling::Scheduler<std::chrono::steady_clock> s;
    s.schedule([&s,&adapter]{adapter.output("Task1");}
    ,std::chrono::steady_clock::now());

    s.schedule([&s,&adapter]{adapter.output("Task2");}
    ,std::chrono::steady_clock::now()
    +std::chrono::seconds(2)
    ,std::chrono::seconds(2));

    s.schedule([&s,&adapter]{adapter.output("Task3");}
    ,std::chrono::steady_clock::now()
    +std::chrono::seconds(2)
    ,std::chrono::seconds(2));

    s.schedule([&s,&adapter]{adapter.output("Task4"); s.halt();}
    ,std::chrono::steady_clock::now()
    +std::chrono::seconds(5));

    s.run();
}

void MainWindow::singlton()
{
    QString str = "singlton";
    UI_Bridge adapter(ui->lineEdit,ui->listWidget);
    Singlton<QString>::instance(&str).print(&adapter);
}

void MainWindow::python()
{
    UI_Bridge adapter(ui->lineEdit,ui->listWidget);
    QSharedPointer<PyRun> p { new PyRun("PyTest.py",&adapter)};
//    delete p;
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
