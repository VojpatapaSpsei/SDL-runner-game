#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

SDL_Texture * loadtexture(const char * path);

SDL_Texture * loadtext(const char * fontpath, const char * text, int r, int g, int b, int a, int resolution);
