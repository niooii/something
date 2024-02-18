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
        // Accessors
        inline float x()
        {
            return x_;
        }

        inline float y()
        {
            return y_;
        }
    };
}

#endif //HORSE_POINT_H
