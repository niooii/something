//
// Created by niooi on 3/5/24.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "types.h"
#include "math/vec2.h"
#include "geometry/point.h"

struct Transform
{
    Geometry::Point center{0.f, 0.f};
    Math::Vec2 scale{1.f, 1.f};
    // Clockwise in degrees.
    f32 rotation{0.f};
};

#endif //TRANSFORM_H
