#ifndef MOVEGAMECOMMAND_H
#define MOVEGAMECOMMAND_H
#include "command.h"

class MoveGameCommand : public Command
{
public:
    MoveGameCommand(Game* ptr);
    void execute();
};

#endif // MOVEGAMECOMMAND_H
