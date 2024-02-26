//
// Created by niooi on 2/17/24.
//

#include "rect.h"

namespace Geometry
{
    Rect::Rect()
    : c{Point{}}, w{0}, h{0}
    {
    }

    Rect::Rect(Point center, f32 side_len)
    : c{center}, w{side_len}, h{side_len}
    {
    }

    Rect::Rect(f32 x, f32 y, f32 side_len)
    : c{Point{x, y}}, w{side_len}, h{side_len}
    {
    }

    Rect::Rect(Point center, f32 w_, f32 h_)
    : c{center}, w{w_}, h{h_}
    {
    }

    Rect::Rect(f32 x, f32 y, f32 w_, f32 h_)
    : c{Point{x, y}}, w{w_}, h{h_}
    {
    }

    f32 Rect::area() const
    {
        return this->w * this->h;
    }

    Point Rect::top_left_corner() const
    {
        // spdlog::debug("center: {}, {}\ntop_left_corner: {}, {}", c.x, c.y, this->c.x - this->w/2.f, this->c.y + this->h/2.f);
        return Point{this->c.x - this->w/2.f, this->c.y - this->h/2.f};
    }

    Point Rect::top_right_corner() const
    {
        return Point{this->c.x + this->w/2.f, this->c.y - this->h/2.f};
    }

    Point Rect::bottom_left_corner() const
    {
        return Point{this->c.x - this->w/2.f, this->c.y + this->h/2.f};
    }

    Point Rect::bottom_right_corner() const
    {
        return Point{this->c.x + this->w/2.f, this->c.y + this->h/2.f};
    }

    bool Rect::contains_point(Point& point) const
    {
        return
        point.x <= this->c.x + this->w && point.x >= this->c.x
        && point.y <= this->c.y + this->h && point.y >= this->c.y;
    }

    bool Rect::operator==(const Rect& other) const
    {
        return c == other.c && w == other.w && h == other.h;
    }

    bool Rect::operator!=(const Rect& other) const
    {
        return !(*this == other);
    }
}
