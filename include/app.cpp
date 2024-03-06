#include "app.h"

App::App(Render::BackendType render_backend_type)
    : render_backend_type_{render_backend_type},
    renderer_{Render::Renderer{render_backend_type}}
{
#ifdef WIN32
    SetProcessDPIAware();
#endif
    SDL_Init(SDL_INIT_EVERYTHING);
    CreateNewWindow(
        "messhhaw",
        500,
        300,
        600,
        600,
        true
    );
    renderer_.Init(main_window_->sdl_window());
}

App::~App()
{
    for (auto& [window_id, window] : windows_)
    {
        delete window;
    }
    SDL_Quit();
}

Window* App::CreateNewWindow(
        const char* name,
        u32 x,
        u32 y,
        u16 width,
        u16 height,
        bool is_main_window
    )
{
    Window* win = new Window{name, x, y, width, height, render_backend_type_};

    windows_[win->window_id()] = win;

    if (is_main_window)
    {
        main_window_ = win;
    }

    main_window_->CaptureMouse(true);

    return win;
}

bool App::DestroyWindow(u32 window_id)
{
    delete windows_[window_id];
    windows_.erase(window_id);

    // TODO! do something here idk
    return true;
}

void App::DrawFrame()
{
    renderer_.DrawTest();
}

void App::Update()
{
    // update time values
    last_ = now_;
    now_ = SDL_GetPerformanceCounter();
    delta_time_ = (now_ - last_) / static_cast<f64>(SDL_GetPerformanceFrequency());
    elapsed_time_ = SDL_GetTicks64() / 1000.f;

    // handle window updates and events
    PollEvents();

    // handle updating input manager singletons
    GetMouse()->Update();
    GetKeyboard()->Update();

    for (auto& [window_id, window] : windows_)
    {
        // window->transform.w = 100.f * abs(sin(elapsed_time_)) + 200;
        // window->transform.h = 100.f * abs(sin(elapsed_time_)) + 200;
        // window->transform.c = Geometry::Point{static_cast<f32>(GetMouse()->x()), static_cast<f32>(GetMouse()->y())};
        window->Update();
    }

    for (auto& [id, component] : render_components_)
    {
        // TODO! make better later i cba rn
        component->DoOnPress();
        component->DoOnHold(delta_time_);
        component->DoOnRelease();

        component->Draw(&this->renderer_);
    }

    // spdlog::debug("{}, {}", GetMouse()->x_rel(), GetMouse()->y_rel());
    main_window_->AlwaysFocused(true);

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
        Window* target_window = GetWindow(window_id);
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
            case SDL_KEYDOWN:
            spdlog::debug("keydodwn event");
            break;
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
    Window* target_window = GetWindow(window_id);
    switch (window_event)
    {
        // may be broken. a good solution is to just toggle off being able to resize the window LOL
    case SDL_WINDOWEVENT_RESIZED:
        {
            i32 w = e_.window.data1;
            i32 h = e_.window.data2;

            // TODO!
            Geometry::Point old_center = target_window->transform.c;
            target_window->transform.w = w;
            target_window->transform.h = h;

            i32 x_, y_;
            SDL_GetWindowPosition(target_window->sdl_window(), &x_, &y_);

            Geometry::Point new_center = Geometry::Rect::TopLeftToCenter(x_, y_, w, h);
            target_window->transform.c = new_center;

        }
        break;

    case SDL_WINDOWEVENT_MOVED:
        {
            i32 x = e_.window.data1;
            i32 y = e_.window.data2;

            Geometry::Point new_center = Geometry::Rect::TopLeftToCenter(x, y, target_window->width(), target_window->height());
            target_window->transform.c = new_center;
            spdlog::debug("{}, {}", x, y);
        }
        break;

    case SDL_WINDOWEVENT_CLOSE:
        {
            spdlog::debug("Window closed...");
            DestroyWindow(window_id);
            break;
        }

    case SDL_WINDOWEVENT_FOCUS_LOST:
        if (target_window != nullptr)
        {
            target_window->UpdateWindowFocusStatus(false);
        }
        break;

    case SDL_WINDOWEVENT_FOCUS_GAINED:
        {
            target_window->UpdateWindowFocusStatus(true);
            break;
        }
    }
}



