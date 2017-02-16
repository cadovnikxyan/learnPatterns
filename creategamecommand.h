#ifndef CREATEGAMECOMMAND_H
#define CREATEGAMECOMMAND_H
#include "command.h"

class CreateGameCommand : public Command
{
public:
    CreateGameCommand(Game* ptr);
    void execute();
};

#endif // CREATEGAMECOMMAND_H
