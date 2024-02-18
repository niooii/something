//
// Created by niooi on 2/17/24.
//

#include "vec2.h"

namespace Math
{
    // Constructors

    // Operators
    // Operators
    Vec2 Vec2::operator+(const Vec2& other) const
    {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2& Vec2::operator+=(const Vec2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2 Vec2::operator-(const Vec2& other) const
    {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2& Vec2::operator-=(const Vec2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2 Vec2::operator*(float scalar) const
    {
        return Vec2(x * scalar, y * scalar);
    }

    Vec2& Vec2::operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vec2 Vec2::operator/(float scalar) const
    {
        if (scalar != 0.0f)
        {
            return Vec2(x / scalar, y / scalar);
        }
        // Handle division by zero or very small scalar
        // (you may want to throw an exception or handle it in a way that makes sense for your application)
        return Vec2();
    }

    Vec2& Vec2::operator/=(float scalar)
    {
        if (scalar != 0.0f)
        {
            x /= scalar;
            y /= scalar;
        }
        // Handle division by zero or very small scalar
        // (you may want to throw an exception or handle it in a way that makes sense for your application)
        return *this;
    }

    Vec2 Vec2::operator-() const
    {
        return Vec2(-x, -y);
    }

    bool Vec2::operator==(const Vec2& other) const
    {
        return (x == other.x) && (y == other.y);
    }

    bool Vec2::operator!=(const Vec2& other) const
    {
        return !(*this == other);
    }
} // Math
