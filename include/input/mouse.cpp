//
// Created by niooi on 2/26/24.
//

#include "mouse.h"

Mouse* Mouse::instance_ = nullptr;

Mouse::Mouse()
{
}

Mouse* Mouse::GetInstance()
{
    if (instance_ == nullptr)
    {
        instance_ = new Mouse();
    }

    return instance_;
}

void Mouse::Update()
{
    up_to_date_ = false;
}

i32 Mouse::x()
{
    if (!up_to_date_)
    {
        SDL_GetGlobalMouseState(&this->x_, &this->y_);
        up_to_date_ = true;
    }

    return x_;
}

i32 Mouse::y()
{
    if (!up_to_date_)
    {
        SDL_GetGlobalMouseState(&this->x_, &this->y_);
        up_to_date_ = true;
    }

    return y_;
}

void Mouse::MoveToRelative(Window* window, Geometry::Point rel_p)
{
    SDL_WarpMouseInWindow(window->sdl_window(), std::lround(rel_p.x), std::lround(rel_p.y));
}

void Mouse::MoveToRelative(Window* window, f32 rel_x, f32 rel_y)
{
    SDL_WarpMouseInWindow(window->sdl_window(), std::lround(rel_x), std::lround(rel_y));
}

void Mouse::MoveToAbsolute(Geometry::Point p)
{
    SDL_WarpMouseGlobal(std::lround(p.x), std::lround(p.y));
}

void Mouse::MoveToAbsolute(f32 x, f32 y)
{
    SDL_WarpMouseGlobal(std::lround(x), std::lround(y));
}



