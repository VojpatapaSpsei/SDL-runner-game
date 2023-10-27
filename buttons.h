#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

class Buttons
{
public:
    Buttons(const char * path, int Originalwidht, int Originalheight,  int widht, int height, int Xpos, int Ypos);
    ~Buttons();
    void update();
    void render();

    bool isclicked;

private:
    SDL_Rect dst;
    SDL_Rect src;

    int originalwidht;
    int originalheight;

    SDL_Texture * tex;
    bool ishovered;
};