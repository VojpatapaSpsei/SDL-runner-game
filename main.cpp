#include "game.h"

Game * game;

int WinMain(int argc, char * argv[])
{
    game = new Game();

    while(game->runnin())
    {
        game->handleEvents();

        if(game->state == game->welcome)
        {
            game->update_welcome();
            game->render_welcome();
        }
        else if(game->state == game->game)
        {
            game->update_game();
            game->render_game();
        }
        else if(game->state == game->settings)
        {
            game->update_settings();
            game->render_settings();
        }
        else if(game->state == game->end)
        {
            game->update_end();
            game->render_end();
        }
    }
    delete game;

    return 0;
}
