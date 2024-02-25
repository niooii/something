#ifndef SDLGAMEFRAMEWORK_APP_H
#define SDLGAMEFRAMEWORK_APP_H

#include "render/components/render_component.h"

#include "platform/SDL2_includes.h"

#include <vector>
#include <map>
#include <expected>

#include "render/renderer.h"

class App
{
    enum AppError
    {
        CouldNotLoadTexture,
        TextureIdNonexistent
    };

private:
    bool requested_quit_;
    std::vector<Render::RenderComponent> render_components_;

    SDL_Window* window_{nullptr};
    Render::Renderer renderer_;
    std::map<const char*, SDL_Texture*> texture_map_;

public:
    App(Render::BackendType render_backend_type);
    ~App();
    std::expected<void, AppError> AddTexture(const char* texture_id, const char* path);
    std::expected<void, AppError> AddRenderComponent();

    void DrawFrame();
    void HandleEvents();
    bool RequestedQuit();
};


#endif
