#include "object.h"
#include "game.h"
#include "texturemanager.h"

Object::Object(const char *path, int width, int height, int Xpos, int Ypos)
{
    texuture = loadtexture(path);

    dst.w = width;
    dst.h = height;
    dst.x = Xpos;
    dst.y = Ypos;
}

void Object::update()
{

}

void Object::render()
{
  SDL_RenderCopy(Game::renderer, texuture, NULL, &dst);
};