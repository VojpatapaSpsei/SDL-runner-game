#include "sprite.h"
#include "additional_functions.h"
#include "texturemanager.h"
#include "game.h"

int Sprite::frameCounter;

Sprite::Sprite(const char * path, int original_width, int original_height, int elements_amount, int width, int height, int frame_count, bool activity, int x_pos, int y_pos)
{
    active = activity;
    previous_state = false;

    texture = loadtexture(path);
    src.x=0;
    src.y=0;
    src.w=original_width/elements_amount;
    src.h=original_height;

    dst.x = x_pos;
    dst.y = y_pos;
    dst.w=width;
    dst.h=height;

    frameGoal = frame_count;

    original_width_w = original_width;
    elements_amount_w = elements_amount;

    frameCounter = 0;
}

void Sprite::update(float x_pos, float y_pos)
{
    if(active)
    {
        dst.x = x_pos;
        dst.y = y_pos;

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