#include "creategamecommand.h"

CreateGameCommand::CreateGameCommand(Game* ptr):Command (ptr)
{

}

void CreateGameCommand::execute()
{
    ptr_game->create();
}
