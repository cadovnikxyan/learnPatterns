#ifndef MOVECONSTRUCTOR_H
#define MOVECONSTRUCTOR_H
#include "ui_bridge.h"
#include <vector>


template<typename T>
class moveContainer{
private:
    std::vector<T>* v;
    UI_Bridge* ui;
public:
    moveContainer(UI_Bridge* ui_):ui(ui_){
        v= new std::vector<T>;
        for(int i=0;i<10;++i){
            v->push_back(i);
        }
        QString info="moveContainer constructor";
        ui->output(info +QString(" vector elements: ")+ QString::number(v->size()));

    }

    moveContainer(const moveContainer& m){
        ui=m.ui;
        v=m.v;
         QString info="moveContainer copy constructor";
        ui->output(info +QString(" vector elements: ")+ QString::number(v->size()));

    }

    moveContainer(moveContainer&& m){
        ui=m.ui;
        v=m.v;
        delete m.v;
        m.v=nullptr;
        QString info="moveContainer move constructor";
        ui->output(info +QString(" vector elements: ")+ QString::number(v->size()));

    }

    moveContainer& operator=(const moveContainer& m){
        ui=m.ui;
        v=m.v;
        QString info="moveContainer copy operator";
        ui->output(info +QString(" vector elements: ")+ QString::number(v->size()));
        return *this;
    }

    moveContainer& operator=(moveContainer&& m){
        ui=m.ui;
        v=m.v;
        delete m.v;
        m.v=nullptr;
        QString info="moveContainer move operator";
         ui->output(info +QString(" vector elements: ")+ QString::number(v->size()));
        return *this;
    }

   ~moveContainer(){
        delete v;
        ui->output("moveContainer destructor");
    }
    void info(){
        QString v_elem= "0";
        if(v!=nullptr){
            v_elem=QString::number(v->size());
        }
        ui->output(QString(" vector elements: ")+ v_elem);
    }
};



template<typename T>
class moveconstructor
{
public:
    moveconstructor(){

    }

    moveconstructor(const moveconstructor& m){

    }

    moveconstructor(moveconstructor&& m){

    }

    moveconstructor& operator=(const moveconstructor& m){

    }

    moveconstructor& operator=(const moveconstructor&& m){

    }

   ~moveconstructor(){

    }
};




#endif // MOVECONSTRUCTOR_H
