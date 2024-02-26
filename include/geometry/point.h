//
// Created by niooi on 2/17/24.
//

#ifndef HORSE_POINT_H
#define HORSE_POINT_H

#include <cmath>
#include "types.h"
#include "math/vec2.h"


namespace Geometry
{
    using Math::Vec2;
    class Point
    {
    public:
        // Contructors
        Point();

        Point(f32 x, f32 y);

        // Accessors
        f32 x;
        f32 y;

        // Other
        f32 distance(const Point& other) const;

        bool operator==(const Point& other) const;
        bool operator!=(const Point& other) const;
        Point operator+(const Vec2& other) const;
        Point& operator+=(const Vec2& other);
        Point operator-(const Vec2& other) const;
        Point& operator-=(const Vec2& other);

    };
}

#endif //HORSE_POINT_H
