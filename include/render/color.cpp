//
// Created by beyon on 3/10/2024.
//

#include "color.h"

Color::Color() : r{0.f}, g{0.f}, b{0.f}, a{0.f}
{
}

Color::Color(const f32 r, const f32 g, const f32 b) : r{r}, g{g}, b{b}, a{1.0f}
{
}

Color::Color(const f32 r, const f32 g, const f32 b, const f32 a) : r{r}, g{g}, b{b}, a{a}
{
}

// const color declarations
const Color Color::RED{1.f, 0.f, 0.f, 1.f};
const Color Color::GREEN{0.f, 1.f, 0.f, 1.f};
const Color Color::BLUE{0.f, 0.f, 1.f, 1.f};
const Color Color::WHITE{1.f, 1.f, 1.f, 1.f};
const Color Color::BLACK{0.f, 0.f, 0.f, 1.f};
const Color Color::GREY{0.2f, 0.2f, 0.2f, 1.f};
