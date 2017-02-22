#ifndef GAME_H
#define GAME_H
#include <QString>
#include "ui_bridge.h"
class Game
{
public:
    Game(UI_Bridge* adapter);
    void create();
    void open(const QString& file);
    void save (const QString& file);
    void move(const QString& move);
    UI_Bridge* ui;


};

#endif // GAME_H
