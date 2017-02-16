#include "game.h"
#include <QDebug>
Game::Game(UIAdapter *adapter)
{
    ui=adapter;
}

void Game::create()
{
    qDebug()<<"Game Create!";
    ui->output("Game Create!");
}

void Game::open(const QString &file)
{
    qDebug()<<"Game open "<<file;
   ui->output(QString("Game open ")+ file );
}

void Game::save(const QString &file)
{
    qDebug()<<"Game save "<<file;
    ui->output(QString("Game save ")+ file );
}

void Game::move(const QString &move)
{
    qDebug()<<"Game move "<<move;
    ui->output(QString("Game move ")+ move );
}

QString Game::getPlayerInput(const QString &promt)
{

    return QString(""); /*заглушка*/
}
