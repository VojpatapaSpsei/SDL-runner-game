#include "game.h"
#include "texturemanager.h"

bool Game::arrowup;
bool Game::space;
bool Game::w;
bool Game::arrowdown;
bool Game::s;
bool Game::arrowleft;
bool Game::a;
bool Game::arrowright;
bool Game::d;
bool Game::enter;
bool Game::backspace;
bool Game::esc;
bool Game::rightclick;
bool Game::leftclick;
bool Game::scrollup;
bool Game::scrolldown;

const Uint8 * Game::keyboardstate;

SDL_Point Game::mouse;

SDL_Renderer * Game::renderer = NULL;
SDL_Texture * image;
SDL_Texture * text;

Game::Game(const char * nazev_okna, int widht, int height)
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

    window = SDL_CreateWindow(nazev_okna, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, widht, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 50);

    keyboardstate = SDL_GetKeyboardState(nullptr);

    image = loadtexture("image.png");
    text = loadtext("font.ttf", "testing text", 255, 0, 0, 255, 50);
}

void Game::handleEvents()
{
    SDL_GetMouseState(&mx,&my);

    scrolldown = false;
    scrollup = false;
    rightclick = false;
    leftclick = false;

    arrowup = keyboardstate[SDL_SCANCODE_UP];
    space = keyboardstate[SDL_SCANCODE_SPACE];
    w = keyboardstate[SDL_SCANCODE_W];

    arrowdown = keyboardstate[SDL_SCANCODE_DOWN];
    s = keyboardstate[SDL_SCANCODE_S];

    arrowleft = keyboardstate[SDL_SCANCODE_LEFT];
    a = keyboardstate[SDL_SCANCODE_A];

    arrowright = keyboardstate[SDL_SCANCODE_RIGHT];
    d = keyboardstate[SDL_SCANCODE_D];

    enter = keyboardstate[SDL_SCANCODE_RETURN];
    backspace = keyboardstate[SDL_SCANCODE_BACKSPACE];
    esc = keyboardstate[SDL_SCANCODE_ESCAPE];

    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
        {
            running = false;
        }
        else if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                leftclick = true;
            }
            else if(event.button.button == SDL_BUTTON_RIGHT)
            {
                rightclick = true;
            }
        }
        else if(event.type == SDL_MOUSEBUTTONUP)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                leftclick = false;
            }
            else if(event.button.button == SDL_BUTTON_RIGHT)
            {
                rightclick = false;
            }
        }
        else if(event.type == SDL_MOUSEWHEEL)
        {
            if(event.wheel.y > 0)
            {
                scrollup = true;
            }
            else if(event.wheel.y < 0)
            {
                scrolldown = true;
            }
        }
    }
}

void Game::update_welcome()
{
    if (arrowup == true || space == true || w == true)
    {
        printf("Skacu ! \n");
    }

    if (arrowdown == true || s == true)
    {
        printf("kricim se ! \n");
    }

    if (arrowleft == true || a == true)
    {
        printf("jdu vlevo ! \n");
    }

    if (arrowright == true || d == true)
    {
        printf("jdu vpravo ! \n");
    }
    if (enter == true)
    {
        printf("enteruju ! \n");
    }
    if(backspace == true)
    {
        printf("mazu ! \n");
    }
    if(esc == true)
    {
        printf("escapuju ! \n");
    }
    if(scrollup == true)
    {
        printf("scroluju nahoru ! \n");
    }
    if(scrolldown == true)
    {
        printf("scrolluju dolu ! \n");
    }
    if(rightclick == true)
    {
        printf("rajt klikuju ! \n");
    }
    if(leftclick == true)
    {
        printf("left klikuju ! \n");
    }

    printf("pozice mysi : x=%d y=%d \n",mx,my);

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