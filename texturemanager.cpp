#include "game.h"
#include "texturemanager.h"

SDL_Texture * tex;
TTF_Font * font;
SDL_Surface * sur;
SDL_Color col;

SDL_Texture * loadtexture(const char * path)
{
    sur = IMG_Load(path);
    if(!sur)
    {
        printf("%s \n", IMG_GetError());
    }
    tex = SDL_CreateTextureFromSurface(Game::renderer,sur);
    SDL_FreeSurface(sur);

    printf("textura vytvorena \n");

    return tex;
}

SDL_Texture * loadtext(const char * fontpath, const char * text, int r, int g, int b, int a, int resolution)
{
    font = TTF_OpenFont(fontpath, resolution);
    col.r = r;
    col.g = g;
    col.b = b;
    col.a = a;

    sur = TTF_RenderText_Solid(font, text, col);
    tex = SDL_CreateTextureFromSurface(Game::renderer, sur);
    TTF_CloseFont(font);
    SDL_FreeSurface(sur);

    return tex;
}

void changetext(SDL_Texture ** texture, const char * fontpath, const char * text, int r, int g, int b, int a, int resolution)
{
    font = TTF_OpenFont(fontpath, resolution);
    col.r = r;
    col.g = g;
    col.b = b;
    col.a = a;

    sur = TTF_RenderText_Solid(font, text, col);
    SDL_DestroyTexture(*texture);
    *texture = SDL_CreateTextureFromSurface(Game::renderer, sur);
    TTF_CloseFont(font);
    SDL_FreeSurface(sur);
}