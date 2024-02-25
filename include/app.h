#ifndef SDLGAMEFRAMEWORK_APP_H
#define SDLGAMEFRAMEWORK_APP_H

#include "render/components/render_component.h"

#include "platform/SDL2_includes.h"

#include <vector>
#include <map>
#include <expected>

class App {
    enum AppError {
        CouldNotLoadTexture,
        TextureIdNonexistent
    };
private:
    bool requested_quit_;
    std::vector<Render::RenderComponent> render_components_;

    // SDL2 internals
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    std::map<const char*, SDL_Texture*> texture_map_;

public:
    App();
    ~App();
    std::expected<void, AppError> AddTexture(const char* texture_id, const char* path);
    std::expected<void, AppError> AddRenderComponent();

    void DrawFrame();
    void HandleEvents();
    bool RequestedQuit();
};


#endif
