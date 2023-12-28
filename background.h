#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

class Background
{
public:
    Background(const char * path, int widht, int height, int y_position);
    void update(float speed);
    void render();
    ~Background();

private:
    float Speed;
    SDL_Rect dst;
    float Xpos;
    SDL_Texture * texture;
};