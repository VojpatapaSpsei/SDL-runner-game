#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

typedef struct CHANGE_VALUE_LINEAR_PARAMETERS
{
    float * value;
    int miliseconds;
    float goal_value;
}CHANGE_VALUE_LINEAR_PARAMETERS;

void * changeValueLinear_thread(void * arg);
void changeValueLinear(float * value, int miliseconds, float goal_value);