#ifndef OPENGAMECOMMAND_H
#define OPENGAMECOMMAND_H
#include "command.h"

class OpenGameCommand : public Command
{
public:
    OpenGameCommand(Game* ptr);
    void execute();
};

#endif // OPENGAMECOMMAND_H
