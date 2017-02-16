#ifndef SAVEGAMECOMMAND_H
#define SAVEGAMECOMMAND_H
#include "command.h"

class SaveGameCommand : public Command
{
public:
    SaveGameCommand(Game *ptr);
    void execute();
};

#endif // SAVEGAMECOMMAND_H
