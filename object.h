#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <time.h>
#include <math.h>

class Object
{
public:
    Object(const char * path, int width, int height, int Xpos, int Ypos);
    void update();
    void render();
    ~Object();

private:
    SDL_Texture * texuture;
    SDL_Rect dst;
};