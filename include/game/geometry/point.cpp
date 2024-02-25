//
// Created by niooi on 2/17/24.
//

#include "point.h"

namespace Geometry
{
    Point::Point() : x(0.f), y(0.f)
    {
    }

    Point::Point(const float x_, const float y_) : x(x_), y(y_)
    {
    }

    float Point::distance(const Point& other)
    {
        return sqrtf((other.x - this->x) * (other.x - this->x) + (other.y - this->y) * (other.y - this->y));
    }
}
