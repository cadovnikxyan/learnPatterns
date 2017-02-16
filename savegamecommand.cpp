#include "savegamecommand.h"

SaveGameCommand::SaveGameCommand(Game* ptr): Command(ptr)
{

}

void SaveGameCommand::execute()
{

    QString save = ptr_game->ui->getInput();
    ptr_game->save(save);
}

