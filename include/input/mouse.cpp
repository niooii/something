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
    global_up_to_date_ = false;
}

i32 Mouse::x()
{
    if (!global_up_to_date_)
    {
        SDL_GetGlobalMouseState(&this->x_global_, &this->y_global_);
        global_up_to_date_ = true;
    }

    return x_global_;
}

i32 Mouse::y()
{
    if (!global_up_to_date_)
    {
        SDL_GetGlobalMouseState(&this->x_global_, &this->y_global_);
        global_up_to_date_ = true;
    }

    return y_global_;
}

i32 Mouse::x_rel()
{
    if (!rel_up_to_date_)
    {
        SDL_GetRelativeMouseState(&this->x_rel_, &this->y_rel_);
        rel_up_to_date_ = true;
    }

    return x_rel_;
}

i32 Mouse::y_rel()
{
    if (!rel_up_to_date_)
    {
        SDL_GetRelativeMouseState(&this->x_rel_, &this->y_rel_);
        rel_up_to_date_ = true;
    }

    return y_rel_;
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



