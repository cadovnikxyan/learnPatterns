#ifndef GAME_H
#define GAME_H
#include <QString>
#include "uiadapter.h"
class Game
{
public:
    Game(UIAdapter* adapter);
    void create();
    void open(const QString& file);
    void save (const QString& file);
    void move(const QString& move);
    QString getPlayerInput(const QString& promt);
    UIAdapter* ui;


};

#endif // GAME_H
