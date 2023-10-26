#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

class Game
{
public:
    Game();
    ~Game();
    void handleEvents();
    void update_welcome();
    void update_game();
    void update_settings();
    void update_end();
    void render_welcome();
    void render_game();
    void render_settings();
    void render_end();
    bool runnin();

    static SDL_Renderer * renderer;

    typedef enum
    {
        welcome = 1, game = 2, settings = 3, end = 4
    }STATES;

    STATES state;
private:
    SDL_Window * window;
    SDL_Event event;
    bool running;
};