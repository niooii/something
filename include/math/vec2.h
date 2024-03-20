//
// Created by niooi on 2/17/24.
//

#ifndef VEC2_H
#define VEC2_H
#include <spdlog/spdlog.h>

namespace Geometry
{
    class Point;
}

namespace Math
{
    class Vec2
    {
    public:
        // Attributes
        // (yes everything is public but i don't want to
        // feel pain doing something like
        // vec.set_x(vec.x() + 1); ykwim like
        // vec.x += 1 is jus easier and more concise
        // so i would like to reinstate that i know what
        // encapsulation is but i just am not using it for this specific
        // task because i believe it would be easier on me
        // as the developer. YIPPE !)
        float x;
        float y;

        // Constructors
        Vec2();
        Vec2(float x, float y);

        // Operators
        Vec2 operator+(const Vec2& other) const;
        Vec2& operator+=(const Vec2& other);

        Vec2 operator-(const Vec2& other) const;
        Vec2& operator-=(const Vec2& other);

        Vec2 operator*(float scalar) const;
        Vec2& operator*=(float scalar);

        Vec2 operator/(float scalar) const;
        Vec2& operator/=(float scalar);

        Vec2 operator-() const;

        bool operator==(const Vec2& other) const;
        bool operator!=(const Vec2& other) const;

        // Other
        float magnitude();
        Vec2 normalized();
        void Normalize();
        Vec2 rotated(float angle_deg);
        void Rotate(float angle_deg);
        Vec2 rotated_around_point(float angle_deg, Geometry::Point& point);
        void Rotate_around_point(float angle_deg, Geometry::Point& point);

        // Returns angle from the positive x axis direction.
        float angle();

        // Returns angle relative to another vector.
        // Follows common math conventions
        // eg clockwise from original vec to other is negative
        // & counterclockwise from original vec is positive
        // param axis_vec represents the x-axis.
        float angle_relative_to(Vec2& axis_vec);
    };
} // Math

#endif //VEC2_H
