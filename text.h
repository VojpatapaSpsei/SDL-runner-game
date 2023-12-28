#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <time.h>
#include <math.h>


class Text
{
public:
    Text(const char * font, const char * text, int width, int height, int Xpos, int Ypos, int r, int g, int b, int a, int resolution);
    ~Text();

    void update(const char * font, const char * text, int width, int height, int Xpos, int Ypos, int r, int g, int b, int a, int resolution);

    void render();

private:

    SDL_Texture * texture;
    SDL_Rect dst;
    SDL_Rect src;
};