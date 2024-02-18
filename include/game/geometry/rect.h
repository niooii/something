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
    private:
        // Center point
        Point c_;
        float w_;
        float h_;

    public:
        // Constructors


        // Accessors
        inline Point center()
        {
            return c_;
        }

        inline float w()
        {
            return w_;
        }

        inline float h()
        {
            return h_;
        }

        // Other
        Point top_left_corner();

        Point top_right_corner();

        Point bottom_left_corner();

        Point bottom_right_corner();

        bool contains_point(Point point);
    };
}


#endif //HORSE_RECT_H
