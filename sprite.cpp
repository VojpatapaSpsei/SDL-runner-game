#include "sprite.h"
#include "additional_functions.h"
#include "texturemanager.h"
#include "game.h"

int Sprite::frameCounter;

Sprite::Sprite(const char * path, int original_width, int original_height, int elements_amount, int width, int height, int frame_count, bool activity)
{
    active = activity;
    previous_state = activity;

    texture = loadtexture(path);
    src.x=0;
    src.y=0;
    src.w=original_width/elements_amount;
    src.h=original_height;

    dst.x = 300;
    dst.y = 300;
    dst.w=width;
    dst.h=height;

    frameGoal = frame_count;

    original_width_w = original_width;
    elements_amount_w = elements_amount;

    frameCounter = 0;
}

void Sprite::update()
{
    if(active)
    {
        if (frameCounter % frameGoal==0 && frameCounter != 0)
        {
            src.x += original_width_w / elements_amount_w;
            if (src.x >= original_width_w)
            {
                src.x = 0;
            }
        }
    }
}

void Sprite::render()
{
    if(active)
    {
        SDL_RenderCopy(Game::renderer, texture, &src, &dst);
    }
}