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

    Rect::Rect(float x, float y, float side_len)
    : c{Point{x, y}}, w{side_len}, h{side_len}
    {
    }

    Rect::Rect(float x, float y, float w_, float h_)
    : c{Point{x, y}}, w{w_}, h{h_}
    {
    }

    float Rect::area() const
    {
        return this->w * this->h;
    }

    Point Rect::top_left_corner() const
    {
        return Point{this->c.x - this->w/2.f, this->c.y + this->h/2.f};
    }

    Point Rect::top_right_corner() const
    {
        return Point{this->c.x + this->w/2.f, this->c.y + this->h/2.f};
    }

    Point Rect::bottom_left_corner() const
    {
        return Point{this->c.x - this->w/2.f, this->c.y - this->h/2.f};
    }

    Point Rect::bottom_right_corner() const
    {
        return Point{this->c.x + this->w/2.f, this->c.y - this->h/2.f};
    }

    bool Rect::contains_point(Point& point) const
    {
        return
        point.x <= this->c.x + this->w && point.x >= this->c.x
        && point.y <= this->c.y + this->h && point.y >= this->c.y;
    }
}
