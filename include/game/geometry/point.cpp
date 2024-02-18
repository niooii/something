//
// Created by niooi on 2/17/24.
//

#include "point.h"

namespace Geometry
{
    Point::Point() : x_(0.f), y_(0.f)
    {
    }

    Point::Point(const float x, const float y) : x_(x), y_(y)
    {
    }

    float Point::distance(const Point &other)
    {

    }

    Math::Vec2 Point::vector_to(const Point &other)
    {
        return Math::Vec2{};
    }
}
