#ifndef HUFFMANALGORITHM_H
#define HUFFMANALGORITHM_H
#include <QFileDialog>
#include <QDialog>
#include <QDataStream>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "tree.h"
class HuffmanAlgorithm:public QDialog
{
    QString outFileName,inFileName;
    QLineEdit* lineEdit;
    QVBoxLayout* vblayout;
    QHBoxLayout* hblyaout;
    QPushButton* btn, *inFilebtn;
    void archiving();
public:
    HuffmanAlgorithm(QWidget* parent);
   ~HuffmanAlgorithm();
    QString getOutFileName();
    void setInFileName();
};

#endif // HUFFMANALGORITHM_H
