//
// Created by niooi on 2/17/24.
//

#ifndef HORSE_POINT_H
#define HORSE_POINT_H

#include <cmath>

namespace Geometry
{
    class Point
    {
    public:
        // Contructors
        Point();

        Point(float x, float y);

        // Accessors
        float x;
        float y;

        // Other
        float distance(const Point& other);
    };
}

#endif //HORSE_POINT_H
