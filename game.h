#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <time.h>
#include <math.h>

class Game
{
public:
    Game(const char * nazev_okna, int widht, int height);
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

    static bool arrowup;
    static bool space;
    static bool w;

    static bool arrowdown;
    static bool s;

    static bool arrowleft;
    static bool a;

    static bool arrowright;
    static bool d;

    static bool enter;
    static bool esc;
    static bool backspace;

    static bool rightclick;
    static bool leftclick;
    static bool scrolldown;
    static bool scrollup;

    static const Uint8 * keyboardstate;
    static SDL_Rect mouse;


private:
    SDL_Window * window;
    SDL_Event event;
    bool running;

    int screenwidht;
    int screenheight;
    float scaleX;
    float scaleY;

    float x;

    int volume;
};