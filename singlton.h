#ifndef SINGLTON_H
#define SINGLTON_H
#include <QDebug>
#include "ui_bridge.h"
template<class T>
class Singlton final
{
    Singlton(){
        Singlton(0);
    }

    Singlton(T* t_):t(t_){

    }
    Singlton(const Singlton& _s);
    ~Singlton()=delete;
    Singlton( Singlton&& _s)= delete;
    Singlton& operator=(const Singlton& _s)= delete;
    Singlton& operator=( Singlton&& _s)= delete;
    T* t;
public:
    static Singlton& instance(T* t){
       static Singlton<T> s(t);
       return s;
    }
    void print( UI_Bridge* ui){
        ui->output(*t);
    }

};

#endif // SINGLTON_H
