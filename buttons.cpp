#include "buttons.h"
#include "texturemanager.h"
#include "game.h"

Buttons::Buttons(const char *path, int Originalwidht, int Originalheight, int widht, int height, int Xpos, int Ypos)
{
    tex = loadtexture(path);

    src.x=0;
    src.y=0;
    src.w = Originalwidht/2;
    src.h = Originalheight;

    dst.w = widht;
    dst.h = height;
    dst.x = Xpos;
    dst.y = Ypos;

    originalwidht = Originalwidht;
    originalheight = Originalheight;

    isclicked = false;
    ishovered = false;
}

void Buttons::update()
{
    ishovered = false;
    isclicked = false;

    if(SDL_HasIntersection(&dst, &Game::mouse))
    {
        ishovered = true;
        src.x = originalwidht/2;
    }
    else
    {
        src.x=0;
    }

    if(ishovered == true && Game::leftclick)
    {
        isclicked = true;
    }
}

void Buttons::render()
{
    SDL_RenderCopy(Game::renderer, tex, &src, &dst);
}

Buttons::~Buttons()
{
    SDL_DestroyTexture(tex);
}