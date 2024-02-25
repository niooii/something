//
// Created by niooi on 2/17/24.
//

#ifndef HORSE_RECT_H
#define HORSE_RECT_H


#include "point.h"

namespace Geometry
{
    class Rect
    {
    public:
        // Constructors
        Rect();
        Rect(float x, float y, float side_len);
        Rect(float x, float y, float w, float h);

        // Center point
        Point c;
        float w;
        float h;

        // Other
        float area() const;

        Point top_left_corner() const;

        Point top_right_corner() const;

        Point bottom_left_corner() const;

        Point bottom_right_corner() const;

        bool contains_point(Point& point) const;
    };
}


#endif //HORSE_RECT_H
