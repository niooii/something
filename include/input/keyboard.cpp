//
// Created by niooi on 2/26/24.
//

#include "keyboard.h"

Keyboard* Keyboard::instance_ = nullptr;

Keyboard::Keyboard()
{
    keyboard_state_ = SDL_GetKeyboardState(nullptr);
}

// TODO! important
void Keyboard::InitKeytrackingIfNotInit(Keycode code)
{
    if (is_pressed_.contains(code) == 0)
    {
        is_pressed_[code] = false;
    }
}

void Keyboard::UninitKeytrackingIfNotInUse(Keycode code)
{

}

Keyboard *Keyboard::GetInstance()
{
    if (instance_ == nullptr)
    {
        instance_ = new Keyboard();
    }
    return instance_;
}

void Keyboard::Update()
{
    for (auto& [keycode, is_pressed] : is_pressed_)
    {
        bool currently_pressed = IsKeyDown(keycode);
        if (currently_pressed && !is_pressed)
        {
            is_pressed = true;
            on_key_press_callbacks_[keycode]();
        }
        else if (!currently_pressed && is_pressed)
        {
            is_pressed = false;
            on_key_release_callbacks_[keycode]();
        }
    }
}

bool Keyboard::IsKeyDown(const Keycode keycode) const
{
    return keyboard_state_[keycode] == 1;
}

void Keyboard::SetKeyDownCallback(Keycode keycode, std::function<void()> callback)
{
    on_key_press_callbacks_[keycode] = callback;
    InitKeytrackingIfNotInit(keycode);
}

void Keyboard::SetKeyUpCallback(Keycode keycode, std::function<void()> callback)
{
    on_key_release_callbacks_[keycode] = callback;
    InitKeytrackingIfNotInit(keycode);
}


