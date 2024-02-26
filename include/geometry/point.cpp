//
// Created by niooi on 2/17/24.
//

#include "point.h"

namespace Geometry
{
    Point::Point() : x(0.f), y(0.f)
    {
    }

    Point::Point(const f32 x_, const f32 y_) : x(x_), y(y_)
    {
    }

    f32 Point::distance(const Point& other) const
    {
        return sqrtf((other.x - this->x) * (other.x - this->x) + (other.y - this->y) * (other.y - this->y));
    }

    bool Point::operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }

    bool Point::operator!=(const Point& other) const
    {
        return !(*this == other);
    }

    Point Point::operator+(const Vec2& other) const
    {
        return Point{x + other.x, y + other.y};
    }

    Point& Point::operator+=(const Vec2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Point Point::operator-(const Vec2& other) const
    {
        return Point{x - other.x, y - other.y};
    }

    Point& Point::operator-=(const Vec2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
}
