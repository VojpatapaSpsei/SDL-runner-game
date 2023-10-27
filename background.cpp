#include "background.h"
#include "texturemanager.h"
#include "game.h"

Background::Background(const char * path, int widht, int height, int y_position)
{
    texture = loadtexture(path);

    dst.w = widht;
    dst.h = height;
    dst.y = y_position;
    dst.x = 0;
    Xpos = 0;
}

void Background::update(float speed)
{
    Speed = speed;
    Xpos -= Speed;
    if(Xpos<=-dst.w)
    {
        Xpos = 0;
    }
    dst.x = Xpos;
}

void Background::render()
{
    SDL_RenderCopy(Game::renderer, texture, NULL, &dst);
    dst.x+=dst.w;
    SDL_RenderCopy(Game::renderer, texture, NULL, &dst);
}
