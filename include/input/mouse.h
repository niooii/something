//
// Created by niooi on 2/26/24.
//

#ifndef MOUSEMANAGER_H
#define MOUSEMANAGER_H
#include "types.h"

#include <SDL_mouse.h>

#include "window.h"

class Mouse {
protected:
    Mouse();
    static Mouse* instance_;

    i32 x_, y_;
    bool up_to_date_{false};

public:
    Mouse(Mouse &other) = delete;
    void operator=(const Mouse &) = delete;

    static Mouse* GetInstance();

    void Update();

    i32 x();
    i32 y();
    void MoveToRelative(Window* window, Geometry::Point rel_p);
    void MoveToRelative(Window* window, f32 rel_x, f32 rel_y);
    void MoveToAbsolute(Geometry::Point p);
    void MoveToAbsolute(f32 x, f32 y);
};

inline Mouse* GetMouse()
{
    return Mouse::GetInstance();
}

#endif //MOUSEMANAGER_H
