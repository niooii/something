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


