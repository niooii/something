#ifndef SDLGAMEFRAMEWORK_APP_H
#define SDLGAMEFRAMEWORK_APP_H

#include <expected>
#include <vector>
#include <SDL2/SDL.h>
#include "render_component.h"

class App {
    enum AppError {
        CouldNotLoadTexture,
    };
public:
    App();
    ~App();
    std::expected<void, AppError> AddRenderComponent();

    void DrawFrame();
    void HandleEvents();
    bool RequestedQuit();

private:
    bool requested_quit_;
    std::vector<RenderComponent> render_components_;

    // SDL2 internals
    SDL_Window* window;
    SDL_Renderer* renderer;
};


#endif
