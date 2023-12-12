#include "additional_functions.h"

void *changeValueLinear_thread(void *arg)
{
    CHANGE_VALUE_LINEAR_PARAMETERS *pars = (CHANGE_VALUE_LINEAR_PARAMETERS *)arg;

    int duration = pars->miliseconds;
    float *value = pars->value;
    float goal = pars->goal_value;

    Uint32 startTime = SDL_GetTicks();
    Uint32 elapsedTime;
    float a = (*value-goal) / (float)duration;

    while(duration>0)
    {
        SDL_Delay(1);
        *value = a*duration+goal;
        elapsedTime = SDL_GetTicks()-startTime;
        startTime = SDL_GetTicks();
        duration-=elapsedTime;
        if(duration<=0)
        {
            *value = goal;
        }
    }

    free(pars);
    return NULL;
}

void changeValueLinear(float * value, int miliseconds, float goal_value)
{
    pthread_t thread;

    CHANGE_VALUE_LINEAR_PARAMETERS * pars = (CHANGE_VALUE_LINEAR_PARAMETERS *) malloc(sizeof(CHANGE_VALUE_LINEAR_PARAMETERS));
    pars->value = value;
    pars->miliseconds = miliseconds;
    pars->goal_value = goal_value;

    pthread_create(&thread, NULL, changeValueLinear_thread, (void*)pars);
    pthread_detach(thread);
}