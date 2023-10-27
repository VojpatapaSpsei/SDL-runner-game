#include "game.h"
#include "texturemanager.h"
#include "buttons.h"
#include "background.h"

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
SDL_Rect Game::mouse;
SDL_Renderer * Game::renderer = NULL;

Buttons * play;
Buttons * xit;
Background * road;

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

    window = SDL_CreateWindow(nazev_okna, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, widht, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 50);
    SDL_RenderSetLogicalSize(renderer, widht, height);

    SDL_GetWindowSize(window, &screenwidht, &screenheight);
    scaleX= (float)screenwidht / (float)widht;
    scaleY = (float)screenheight / (float)height;

    keyboardstate = SDL_GetKeyboardState(nullptr);
    mouse.w=1;
    mouse.h=1;

    play = new Buttons("images/buttons/play/play.png",800,275,300,250,widht/2-300/2,height/2-250/2);
    xit = new Buttons("images/buttons/exit/exit.png", 800, 275, 400, 150, 5, 5);

    road = new Background("images/background/celek.png",3600, height, 0);

}

void Game::handleEvents()
{
    SDL_GetMouseState(&mouse.x,&mouse.y);
    mouse.x = mouse.x / scaleX;
    mouse.y = mouse.y / scaleY;

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

float x=0;
float speed;

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

    x=x+0.2;
    speed = 20*sin(0.1*x)+1;

    road->update(speed);
    play->update();
    xit->update();

    if(play->isclicked)
    {
        state = game;
    }
    if(xit->isclicked)
    {
        running = false;
    }


}

void Game::update_game()
{
    xit->update();
    if(xit->isclicked)
    {
        running = false;
    }
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

    road->render();
    play->render();
    xit->render();

    SDL_RenderPresent(renderer);

}

void Game::render_game()
{
    SDL_RenderClear(renderer);

    xit->render();

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