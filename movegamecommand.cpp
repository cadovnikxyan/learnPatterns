#include "movegamecommand.h"

MoveGameCommand::MoveGameCommand(Game *ptr):Command(ptr)
{

}

void MoveGameCommand::execute()
{
    QString move = ptr_game->ui->getInput();
    ptr_game->move(move);
}


