//
// Created by niooi on 2/17/24.
//

#ifndef HORSE_RECT_H
#define HORSE_RECT_H

#include <spdlog/spdlog.h>

#include "point.h"

namespace Geometry
{
    class Rect
    {
    public:
        // Constructors
        Rect();
        Rect(Point center, f32 side_len);
        Rect(f32 x, f32 y, f32 side_len);
        Rect(Point center, f32 w_, f32 h_);
        Rect(f32 x, f32 y, f32 w, f32 h);

        // Center point
        Point c;
        f32 w;
        f32 h;

        // Other
        f32 area() const;

        Point top_left_corner() const;

        Point top_right_corner() const;

        Point bottom_left_corner() const;

        Point bottom_right_corner() const;

        static Point TopLeftToCenter(f32 x, f32 y, f32 w, f32 h )
        {
            return Point{x + w/2.f, y + w/2.f};
        };

        static Point TopLeftToCenter(Point& p, f32 w, f32 h )
        {
            return Point{p.x + w/2.f, p.y + w/2.f};
        };

        bool contains_point(Point& point) const;

        bool operator==(const Rect& other) const;
        bool operator!=(const Rect& other) const;
    };
}


#endif //HORSE_RECT_H
