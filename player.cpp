#include "player.h"
#include "additional_functions.h"
#include "texturemanager.h"
#include "game.h"
#include "sprite.h"

Sprite * running_animation;

Player::Player()
{
    running = true;
    in_air = false;

    x_pos = 25;
    y_pos = 430;

    velocity = 0;

    running_animation = new Sprite("images/player/kovboj_na_koni_V2-running.png", 1740, 105, 12, 300, 300, 3, true, 500, 500);


}

void Player::update()
{
    if(running && (Game::w || Game::space || Game::arrowup))
    {
        velocity = 19;
        running = false;
        in_air = true;
    }
    if(in_air)
    {
        velocity-=0.5;
        y_pos-=velocity;

        if(Game::s || Game::arrowdown)
        {
            velocity-=1;
            y_pos-=velocity;
        }

        if(y_pos>=430)
        {
            y_pos=430;
            in_air = false;
            running = true;
        }
    }

    running_animation->update(x_pos, y_pos);
}

void Player::render()
{


    running_animation->render();
}