#ifndef SDLGAMEFRAMEWORK_APP_H
#define SDLGAMEFRAMEWORK_APP_H

#include "render/components/render_component.h"

#include "platform/SDL2_includes.h"

#include <vector>
#include <map>
#include <expected>

#include "render/renderer.h"

#include "types.h"
#include "window.h"
#include "game/game.h"

class App
{
    enum AppError
    {
        CouldNotLoadTexture,
        TextureIdNonexistent,
    };

private:
    bool should_quit_{false};

    // Window and rendering
    std::vector<Render::RenderComponent> render_components_;
    std::map<u32, Window*> windows_;
    Window* main_window_;

    SDL_Event e_{};
    Render::BackendType render_backend_type_;
    Render::Renderer renderer_;
    std::map<const char*, SDL_Texture*> texture_map_;

    // Game
    std::optional<Game> horse_game_;

    // time values
    u64 now_{SDL_GetPerformanceCounter()}, last_{SDL_GetPerformanceCounter()};
    f32 delta_time_{0};
    f32 elapsed_time_{0};

    void PollEvents();
    void HandleWindowEvents(u8 window_event);

public:
    App(Render::BackendType render_backend_type);
    ~App();

    // Accessors
    inline bool should_quit()
    {
        return should_quit_;
    }
    inline Window& get_main_window()
    {
        return *main_window_;
    }
    // Change in time from previous frame to current in seconds.
    inline f32 get_delta_time()
    {
        return delta_time_;
    }
    // Elapsed time since SDL_Library initialization in seconds.
    inline f32 get_elapsed_time()
    {
        return elapsed_time_;
    }

    // Returns the window itself, if failed nullptr
    Window* CreateNewWindow(
        const char* name,
        u32 x,
        u32 y,
        u16 width,
        u16 height,
        bool is_main_window
    );
    inline Window* GetWindow(u32 window_id)
    {
        return windows_.contains(window_id) == 0 ? nullptr : windows_.at(window_id);;
    }
    bool DestroyWindow(u32 window_id);


    std::expected<void, AppError> AddRenderComponent();

    void DrawFrame();
    void Update();
};


#endif
