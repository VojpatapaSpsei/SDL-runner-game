#include "game.h"
#include "texturemanager.h"

SDL_Renderer * Game::renderer = NULL;
SDL_Texture * image;
SDL_Texture * text;

Game::Game()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("Something went wrong with SDL init");
        SDL_Delay(5000);
        exit(0);
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("Something went wrong with SDL_image init");
        SDL_Delay(5000);
        exit(0);
    }

    if (TTF_Init() == -1)
    {
        printf("Something went wrong with SDL_ttf init");
        SDL_Delay(5000);
        exit(0);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("Something went wrong with SDL_mixer init");
        SDL_Delay(5000);
        exit(0);
    }

    running = true;
    state = welcome;

    window = SDL_CreateWindow("Runner", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 540, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 50);

    image = loadtexture("image.png");
    text = loadtext("font.ttf", "test", 255, 0, 0, 255, 1000);
}

void Game::handleEvents()
{
    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
        {
            running = false;
        }
    }
}

void Game::update_welcome()
{

}

void Game::update_game()
{

}

void Game::update_settings()
{

}

void Game::update_end()
{

}


void Game::render_welcome()
{
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer,image, NULL, NULL);
    SDL_RenderCopy(renderer,text, NULL, NULL);

    SDL_RenderPresent(renderer);

    printf(".");
}

void Game::render_game()
{
    SDL_RenderClear(renderer);



    SDL_RenderPresent(renderer);
}

void Game::render_settings()
{
    SDL_RenderClear(renderer);



    SDL_RenderPresent(renderer);
}

void Game::render_end()
{
    SDL_RenderClear(renderer);



    SDL_RenderPresent(renderer);
}

bool Game::runnin()
{
    return running;
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("konec");
}