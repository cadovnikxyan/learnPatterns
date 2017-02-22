#ifndef COMMAND_H
#define COMMAND_H
#include "game.h"
#include "bridge.h"
class Command
{
public:
    virtual ~Command();
    virtual void execute()=0;
protected:
    Command(Game* ptr);
    Game* ptr_game;

};

#endif // COMMAND_H
