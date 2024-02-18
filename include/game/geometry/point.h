//
// Created by niooi on 2/17/24.
//

#ifndef HORSE_POINT_H
#define HORSE_POINT_H

namespace Geometry
{
    class Point
    {
    private:
        float x_;
        float y_;

    public:
        // Contructors
        Point();

        Point(float x, float y);

        // Accessors
        inline float x() { return x_; }

        inline float y() { return y_; };

        // Other
        float distance(const Point& other);
    };
}

#endif //HORSE_POINT_H
