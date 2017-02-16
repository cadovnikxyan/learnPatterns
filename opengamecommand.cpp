#include "opengamecommand.h"

OpenGameCommand::OpenGameCommand(Game* ptr): Command(ptr)
{

}

void OpenGameCommand::execute()
{
    QString open = ptr_game->ui->getInput();
    ptr_game->open(open);
}

