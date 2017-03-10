#include "huffmanalgorithm.h"
#include <QDebug>


HuffmanAlgorithm::HuffmanAlgorithm(QWidget *parent):QDialog(parent)
{
    setModal(true);
    resize(300,400);
    lineEdit = new QLineEdit(this);
    vblayout = new QVBoxLayout(this);
    hblyaout = new QHBoxLayout(this);
    btn = new QPushButton("Архивация");
    inFilebtn = new QPushButton("Файл");
    connect(btn,&QPushButton::clicked,this,&HuffmanAlgorithm::archiving);
    connect(inFilebtn,&QPushButton::clicked,this,&HuffmanAlgorithm::setInFileName);
    hblyaout->addWidget(lineEdit);
    hblyaout->addWidget(btn);
    hblyaout->addWidget(inFilebtn);
    vblayout->addLayout(hblyaout);

}

HuffmanAlgorithm::~HuffmanAlgorithm()
{
    delete btn;
    delete lineEdit;
    delete hblyaout;
    delete vblayout;
}

QString HuffmanAlgorithm::getOutFileName()
{
    return lineEdit->text();
}

void HuffmanAlgorithm::setInFileName()
{
   inFileName = QFileDialog::getOpenFileName(this, tr("Файл для архивации"),"/home/");

}


void HuffmanAlgorithm::archiving()
{

    QFile* file;
    QDataStream* instream;
    tree* t;
    qDebug()<<inFileName;
    outFileName= getOutFileName();
    qDebug()<<outFileName;
    if((!inFileName.isEmpty())&&(!outFileName.isEmpty())){
       file = new QFile(inFileName);
       file->open(QIODevice::ReadOnly);
       t = new tree(std::move(file->readAll().toStdString()));
       file->close();
       t->writeTree();
       delete file;
       file = new QFile(outFileName);
       file->open(QIODevice::WriteOnly);
       instream = new QDataStream(file);
       quint8 buf=0;
       int count=0;
       for(auto x : t->getCode()){
           for(auto n : x.second){
               buf |= x.second[n]<<(7-count++);
               if(count>7){
                   instream->operator <<(buf);
                   buf=0;
                   count= 0;
               }
           }
       }
       file->close();
       delete file;
       t->printTree();
       delete t;
    }



}
