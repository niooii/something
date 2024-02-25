#include "app.h"

App::App(Render::BackendType render_backend_type)
    : renderer_{Render::Renderer{render_backend_type}}
{
    SDL_Init(SDL_INIT_EVERYTHING);

    // Renderer::Init initializes the window as well.
    renderer_.Init(window_);
}

App::~App()
{
    SDL_DestroyWindow(window_);
}
