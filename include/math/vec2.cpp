//
// Created by niooi on 2/17/24.
//

#include "vec2.h"

namespace Math
{
    // Constructors
    Vec2::Vec2() : x{0}, y{0}
    {
    }

    Vec2::Vec2(float x_, float y_) : x{x_}, y{y_}
    {
    }


    // Operators
    Vec2 Vec2::operator+(const Vec2& other) const
    {
        return Vec2{x + other.x, y + other.y};
    }

    Vec2& Vec2::operator+=(const Vec2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2 Vec2::operator-(const Vec2& other) const
    {
        return Vec2{x - other.x, y - other.y};
    }

    Vec2& Vec2::operator-=(const Vec2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2 Vec2::operator*(float scalar) const
    {
        return Vec2{x * scalar, y * scalar};
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
            return Vec2{x / scalar, y / scalar};
        }
        spdlog::warn("Attempted to divide Vec2({}, {}) element-wise by scalar 0. No changes have been made.", x, y);
        return Vec2{x, y};
    }

    Vec2& Vec2::operator/=(float scalar)
    {
        if (scalar != 0.0f)
        {
            x /= scalar;
            y /= scalar;
        }
        spdlog::warn("Attempted to divide Vec2({}, {}) element-wise by scalar 0. No changes have been made.", x, y);
        return *this;
    }

    Vec2 Vec2::operator-() const
    {
        return Vec2{-x, -y};
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
