#include "game.h"

Game * game;

int WinMain(int argc, char * argv[])
{
    game = new Game("Runner", 1440, 810);

    const int FPS = 60;
    Uint32 start;
    int delay = 1000/FPS;
    int time;
    int frametime;
    int count;

    while(game->runnin())
    {
        start = SDL_GetTicks();

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

        count++;
        time = SDL_GetTicks() - start;
        if(delay>time)
        {
            SDL_Delay(delay-time);
        }

        frametime+=SDL_GetTicks()-start;
        if(frametime>=1000)
        {
            printf("%d \n", count);
            frametime = 0;
            count=0;
        }

    }

    delete game;

    return 0;
}
