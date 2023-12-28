#include "text.h"
#include "texturemanager.h"
#include "game.h"

Text::Text(const char * font, const char * text, int width, int height, int Xpos, int Ypos, int r, int g, int b, int a, int resolution)
{
    dst.w = width;
    dst.h = height;
    dst.x = Xpos;
    dst.y = Ypos;

    texture = loadtext(font, text, r, g, b, a, resolution);
}

void Text::update(const char *font, const char *text, int width, int height, int Xpos, int Ypos, int r, int g, int b, int a, int resolution)
{
    dst.w = width;
    dst.h = height;
    dst.x = Xpos;
    dst.y = Ypos;

    changetext(&texture, font, text, r, g, b, a, resolution);
}

void Text::render()
{
    SDL_RenderCopy(Game::renderer, texture, NULL, &dst);
}