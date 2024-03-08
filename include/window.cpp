#include "window.h"

Window::Window(const char* name, u32 x, u32 y, u16 w, u16 h, Render::BackendType render_backend_type)
{
    window_name_ = name;

    // make it so the screen doesn't flicker on KDE
    SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");

    u32 window_creation_flags{};

    switch (render_backend_type)
    {
    case Render::BackendType::OPENGL:
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        window_creation_flags =
            SDL_WINDOW_OPENGL |
                SDL_WINDOW_SHOWN |
                    SDL_WINDOW_RESIZABLE |
                        SDL_WINDOW_ALLOW_HIGHDPI;
        break;
    case Render::BackendType::DIRECTX:
        throw std::runtime_error{"Not implemented! Exiting now..."};
    case Render::BackendType::VULKAN:
        throw std::runtime_error{"Not implemented! Exiting now..."};
    }

    sdl_window_ = SDL_CreateWindow(
            name,
            x,
            y,
            w,
            h,
            window_creation_flags
        );

    window_id_ = SDL_GetWindowID(sdl_window_);

    i32 x_, y_;
    SDL_GetWindowPosition(sdl_window_, &x_, &y_);
    Geometry::Point center = Geometry::Rect::TopLeftToCenter(x_, y_, w, h);

    transform = Geometry::Rect{
        center,
        static_cast<f32>(w),
        static_cast<f32>(h)
    };
    prev_transform_ = transform;
}

Window::~Window()
{
    CaptureMouse(false);
    SDL_DestroyWindow(sdl_window_);
}

void Window::Update()
{
    UpdateTransform();

    if (should_be_always_focused_)
    {
        SDL_RaiseWindow(sdl_window_);
        // this shouldn't be necessary if it actaully worked, but remove later.
        // is_focused_ = true;
    }
}

void Window::SetMouseMotionCallback(void (*callback)(int, int, int, int))
{
    on_mouse_motion_ = callback;
}

void Window::SetMouseButtonDownCallback(void (*callback)(int, int, Uint8))
{
    on_mousebutton_down_ = callback;
}

void Window::SetMouseButtonUpCallback(void (*callback)(int, int, Uint8))
{
    on_mousebutton_up = callback;
}

void Window::SetKeyDownCallback(void (*callback)(SDL_Keycode key,
                                                 Uint16 modifier))
{
    on_keydown_ = callback;
}

void Window::SetKeyUpCallback(void (*callback)(SDL_Keycode key,
                                               Uint16 modifier))
{
    on_keyup_ = callback;
}

// Private
void Window::UpdateTransform()
{
    // update window transform accordingly
    if (prev_transform_.w != transform.w || prev_transform_.h != transform.h)
    {
        if (prev_transform_.c != transform.c)
        {
            prev_transform_.c = transform.c;
        }
        Geometry::Point left_corner = transform.top_left_corner();
        SDL_SetWindowPosition(sdl_window_, left_corner.x, left_corner.y);
        SDL_SetWindowSize(sdl_window_, transform.w, transform.h);
        prev_transform_.w = transform.w;
        prev_transform_.h = transform.h;

    }
    else if (prev_transform_.c != transform.c)
    {
        Geometry::Point left_corner = transform.top_left_corner();
        SDL_SetWindowPosition(sdl_window_, left_corner.x, left_corner.y);
        prev_transform_.c = transform.c;
    }

}

