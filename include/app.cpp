#include "app.h"

App::App()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->window_ = SDL_CreateWindow(
        "hi world",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        800,
        SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
    );

    this->renderer_ = SDL_CreateRenderer(
        window_,
        0,
        SDL_RENDERER_ACCELERATED
    );
}

App::~App()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
}
