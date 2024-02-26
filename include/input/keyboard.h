//
// Created by niooi on 2/26/24.
//

#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <functional>
#include <map>

#include <SDL_scancode.h>
#include <SDL_keyboard.h>

#include "types.h"

enum Keycode
{
    KEY_UNKNOWN = SDL_SCANCODE_UNKNOWN,

    // Alphabet
    KEY_A = SDL_SCANCODE_A, KEY_B = SDL_SCANCODE_B, KEY_C = SDL_SCANCODE_C,
    KEY_D = SDL_SCANCODE_D, KEY_E = SDL_SCANCODE_E, KEY_F = SDL_SCANCODE_F,
    KEY_G = SDL_SCANCODE_G, KEY_H = SDL_SCANCODE_H, KEY_I = SDL_SCANCODE_I,
    KEY_J = SDL_SCANCODE_J, KEY_K = SDL_SCANCODE_K, KEY_L = SDL_SCANCODE_L,
    KEY_M = SDL_SCANCODE_M, KEY_N = SDL_SCANCODE_N, KEY_O = SDL_SCANCODE_O,
    KEY_P = SDL_SCANCODE_P, KEY_Q = SDL_SCANCODE_Q, KEY_R = SDL_SCANCODE_R,
    KEY_S = SDL_SCANCODE_S, KEY_T = SDL_SCANCODE_T, KEY_U = SDL_SCANCODE_U,
    KEY_V = SDL_SCANCODE_V, KEY_W = SDL_SCANCODE_W, KEY_X = SDL_SCANCODE_X,
    KEY_Y = SDL_SCANCODE_Y, KEY_Z = SDL_SCANCODE_Z,

    // Numeric
    KEY_0 = SDL_SCANCODE_0, KEY_1 = SDL_SCANCODE_1, KEY_2 = SDL_SCANCODE_2,
    KEY_3 = SDL_SCANCODE_3, KEY_4 = SDL_SCANCODE_4, KEY_5 = SDL_SCANCODE_5,
    KEY_6 = SDL_SCANCODE_6, KEY_7 = SDL_SCANCODE_7, KEY_8 = SDL_SCANCODE_8,
    KEY_9 = SDL_SCANCODE_9,

    // Function
    KEY_F1 = SDL_SCANCODE_F1, KEY_F2 = SDL_SCANCODE_F2, KEY_F3 = SDL_SCANCODE_F3,
    KEY_F4 = SDL_SCANCODE_F4, KEY_F5 = SDL_SCANCODE_F5, KEY_F6 = SDL_SCANCODE_F6,
    KEY_F7 = SDL_SCANCODE_F7, KEY_F8 = SDL_SCANCODE_F8, KEY_F9 = SDL_SCANCODE_F9,
    KEY_F10 = SDL_SCANCODE_F10, KEY_F11 = SDL_SCANCODE_F11, KEY_F12 = SDL_SCANCODE_F12,

    // Arrow
    KEY_ARROW_UP = SDL_SCANCODE_UP, KEY_ARROW_DOWN = SDL_SCANCODE_DOWN,
    KEY_ARROW_LEFT = SDL_SCANCODE_LEFT, KEY_ARROW_RIGHT = SDL_SCANCODE_RIGHT,

    // Special
    KEY_ENTER = SDL_SCANCODE_RETURN, KEY_SPACE = SDL_SCANCODE_SPACE,
    KEY_TAB = SDL_SCANCODE_TAB, KEY_ESC = SDL_SCANCODE_ESCAPE,
    KEY_BACKSPACE = SDL_SCANCODE_BACKSPACE,

    // Modifiers
    KEY_SHIFT = SDL_SCANCODE_LSHIFT, KEY_CTRL = SDL_SCANCODE_LCTRL,
    KEY_ALT = SDL_SCANCODE_LALT,

    // Symbols
    KEY_GRAVE = SDL_SCANCODE_GRAVE, KEY_MINUS = SDL_SCANCODE_MINUS,
    KEY_EQUAL = SDL_SCANCODE_EQUALS, KEY_LEFT_BRACKET = SDL_SCANCODE_LEFTBRACKET,
    KEY_RIGHT_BRACKET = SDL_SCANCODE_RIGHTBRACKET, KEY_BACKSLASH = SDL_SCANCODE_BACKSLASH,
    KEY_SEMICOLON = SDL_SCANCODE_SEMICOLON, KEY_QUOTE = SDL_SCANCODE_APOSTROPHE,
    KEY_COMMA = SDL_SCANCODE_COMMA, KEY_PERIOD = SDL_SCANCODE_PERIOD,
    KEY_SLASH = SDL_SCANCODE_SLASH,

    // Numpad
    KEY_KP_0 = SDL_SCANCODE_KP_0, KEY_KP_1 = SDL_SCANCODE_KP_1,
    KEY_KP_2 = SDL_SCANCODE_KP_2, KEY_KP_3 = SDL_SCANCODE_KP_3,
    KEY_KP_4 = SDL_SCANCODE_KP_4, KEY_KP_5 = SDL_SCANCODE_KP_5,
    KEY_KP_6 = SDL_SCANCODE_KP_6, KEY_KP_7 = SDL_SCANCODE_KP_7,
    KEY_KP_8 = SDL_SCANCODE_KP_8, KEY_KP_9 = SDL_SCANCODE_KP_9,
    KEY_KP_DECIMAL = SDL_SCANCODE_KP_PERIOD, KEY_KP_DIVIDE = SDL_SCANCODE_KP_DIVIDE,
    KEY_KP_MULTIPLY = SDL_SCANCODE_KP_MULTIPLY, KEY_KP_SUBTRACT = SDL_SCANCODE_KP_MINUS,
    KEY_KP_ADD = SDL_SCANCODE_KP_PLUS, KEY_KP_ENTER = SDL_SCANCODE_KP_ENTER,
    KEY_KP_EQUAL = SDL_SCANCODE_KP_EQUALS,

    // Media
    KEY_VOLUME_UP = SDL_SCANCODE_VOLUMEUP, KEY_VOLUME_DOWN = SDL_SCANCODE_VOLUMEDOWN,
    KEY_MEDIA_PLAY = SDL_SCANCODE_AUDIOPREV, KEY_MEDIA_PAUSE = SDL_SCANCODE_AUDIOPLAY,
    KEY_MEDIA_STOP = SDL_SCANCODE_AUDIOSTOP, KEY_MEDIA_NEXT = SDL_SCANCODE_AUDIONEXT,
};

class Keyboard {
protected:
    Keyboard();
    static Keyboard* instance_;

    const u8* keyboard_state_{nullptr};

    std::map<Keycode, std::function<void()>> on_key_press_callbacks_;
    std::map<Keycode, std::function<void()>> on_key_release_callbacks_;

    // keys contain all the keys present in the maps above
    std::map<Keycode, bool> is_pressed_;

    void InitKeytrackingIfNotInit(Keycode code);
    void UninitKeytrackingIfNotInUse(Keycode code);
public:
    Keyboard(Keyboard &other) = delete;
    void operator=(const Keyboard &) = delete;

    static Keyboard* GetInstance();

    void Update();

    bool IsKeyDown(Keycode keycode) const;
    void SetKeyDownCallback(Keycode keycode, std::function<void()> callback);
    void SetKeyUpCallback(Keycode keycode, std::function<void()> callback);
};

inline Keyboard* GetKeyboard()
{
    return Keyboard::GetInstance();
}

#endif //KEYBOARD_H
