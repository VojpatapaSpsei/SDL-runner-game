#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <time.h>
#include <math.h>

class Sprite
{
public:
    Sprite(const char * path, int original_width, int original_height, int elements_amount, int width, int height, int frame_count, bool activity, int x_pos, int y_pos);
    ~Sprite();
    static int frameCounter;
    void update(float x_pos, float y_pos);
    void render();
    static void counterIncrement();
    bool active;
    bool previous_state;
    SDL_Rect dst;

private:
    SDL_Texture * texture;
    SDL_Rect src;
    int frameGoal;
    int original_width_w;
    int elements_amount_w;
};