#include "app.h"

App::App(
    const char* name,
    const u32 x,
    const u32 y,
    const u16 width,
    const u16 height,
    Render::BackendType render_backend_type
    )
    : renderer_{Render::Renderer{render_backend_type}}
{
#ifdef WIN32
    SetProcessDPIAware();
#endif
    spdlog::debug("Initializing SDL.");
    SDL_Init(SDL_INIT_EVERYTHING);
    Window* win = new Window{"Main", 0, 1080, 600, 600, Render::OPENGL};
    Window* win2 = new Window{"Main2", 1800, 600, 200, 200, Render::OPENGL};
    windows_[win->window_id()] = win;
    windows_[win2->window_id()] = win2;
    main_window_ = win;
    renderer_.Init(name, x, y, width, height, main_window_->sdl_window());
}

App::~App()
{
    for (auto& [window_id, window] : windows_)
    {
        delete window;
    }
    SDL_Quit();
}

void App::DrawFrame()
{
    renderer_.DrawTest();
}

void App::Update()
{
    // compute deltatime
    last_ = now_;
    now_ = SDL_GetPerformanceCounter();
    delta_time_ = (now_ - last_) / static_cast<f64>(SDL_GetPerformanceFrequency());

    // handle window updates and events
    PollEvents();
    for (auto& [window_id, window] : windows_)
    {
        // window->Transform().w += 100.f * delta_time_;
        // window->Transform().h += 100.f * delta_time_;
        window->Transform().c += Math::Vec2{100.f * delta_time_, 100.f * delta_time_};
        window->Update();
    }

    /* Logic updates */
    // window_.transform().h +=  200.f * delta_time_;

    /* Rendering */
    // spdlog::debug("update took {}", delta_time_);
}

// Private
void App::PollEvents()
{
    while (SDL_PollEvent(&e_))
    {
        u32 window_id = e_.window.windowID;
        // Window* target_window = windows_.at(window_id);
        spdlog::debug("event from {}", window_id);
        switch (e_.type)
        {
        case SDL_QUIT:
            // requested_quit_ = true;
            break;

        case SDL_WINDOWEVENT:
            HandleWindowEvents(e_.window.event);
            break;

        // case SDL_MOUSEMOTION:
        //     if (on_mouse_motion_ == nullptr)
        //         continue;
        //     on_mouse_motion_(e_.motion.x, e_.motion.y, e_.motion.xrel, e_.motion.yrel);
        //     break;
        //
        // case SDL_MOUSEBUTTONDOWN:
        //     if (on_mousebutton_down_ == nullptr)
        //         continue;
        //     on_mousebutton_down_(e_.button.x, e_.button.y, e_.button.button);
        //     break;
        //
        // case SDL_MOUSEBUTTONUP:
        //     if (on_mousebutton_up == nullptr)
        //         continue;
        //     on_mousebutton_up(e_.button.x, e_.button.y, e_.button.button);
        //     break;
        //
        // case SDL_KEYDOWN:
        //     if (on_keydown_ == nullptr)
        //         continue;
        //     on_keydown_(e_.key.keysym.sym, e_.key.keysym.mod);
        //     break;
        //
        // case SDL_KEYUP:
        //     if (on_keyup_ == nullptr)
        //         continue;
        //     on_keyup_(e_.key.keysym.sym, e_.key.keysym.mod);
        }
    }
}

void App::HandleWindowEvents(u8 window_event)
{
    u32 window_id = e_.window.windowID;
    Window* target_window = windows_.at(window_id);
    switch (window_event)
    {
    case SDL_WINDOWEVENT_RESIZED:
        {
            i32 w = e_.window.data1;
            i32 h = e_.window.data2;


        }
        break;

    case SDL_WINDOWEVENT_MOVED:
        {
            i32 x = e_.window.data1;
            i32 y = e_.window.data2;

            Geometry::Point new_center = Geometry::Rect::TopLeftToCenter(x, y, target_window->width(), target_window->height());
            target_window->Transform().c = new_center;
            spdlog::debug("{}, {}", x, y);
        }
        break;
    }
}

