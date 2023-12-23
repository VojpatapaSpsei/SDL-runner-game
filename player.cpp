#include "player.h"
#include "additional_functions.h"
#include "texturemanager.h"
#include "game.h"
#include "sprite.h"

Sprite * running_animation;
Sprite * flying_animation;

Player::Player()
{
    running = false;
    in_air = true;

    x_pos = 25;
    y_pos = -310;

    velocity = 0;

    ground = 730;

    running_animation = new Sprite("images/player/kovboj_na_koni_V2-running.png", 1740, 105, 12, 300, 300, 3, false, x_pos, y_pos);
    flying_animation = new Sprite("images/player/kovboj_na_koni_V2-flying.png", 1740, 105, 12, 300, 300, 3, true, x_pos, y_pos);


}

void Player::update()
{
    if(running)
    {
        if(Game::s || Game::arrowdown)
        {
            running_animation->dst.h = 150;
            running_animation->dst.w = 400;
            y_pos = ground - running_animation->dst.h;
        }
        else
        {
            running_animation->dst.h = 300;
            running_animation->dst.w = 300;
            y_pos = ground - running_animation->dst.h;
        }

        if(Game::w || Game::space || Game::arrowup)
        {
            velocity = 19;
            running = false;
            in_air = true;

            running_animation->active = false;
            flying_animation->active = true;
        }
    }
    if(in_air)
    {
        velocity-=0.5;
        y_pos-=velocity;

        if(Game::s || Game::arrowdown)
        {
            if(velocity>0)
            {
                velocity = 0;
            }
            velocity-=3;
            y_pos-=velocity;
        }

        if(y_pos>=ground-flying_animation->dst.h)
        {
            y_pos=430;
            in_air = false;
            running = true;
            running_animation->active = true;
            flying_animation->active = false;
        }
    }

    running_animation->update(x_pos, y_pos);
    flying_animation->update(x_pos,y_pos);
}

void Player::render()
{


    running_animation->render();
    flying_animation->render();
}