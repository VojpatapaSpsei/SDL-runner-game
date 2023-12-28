#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

class Player
{
public:
    Player();
    ~Player();
    void update();
    void render();

private:
    bool running;
    bool in_air;
    float x_pos;
    float y_pos;

    float velocity;
    int ground;
};