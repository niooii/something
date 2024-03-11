//
// Created by beyon on 3/10/2024.
//

#ifndef COLOR_H
#define COLOR_H
#include "types.h"

class Color
{
public:
    // Constructors
    Color();
    Color(f32 r, f32 g, f32 b);
    Color(f32 r, f32 g, f32 b, f32 a);

    // Attributes
    f32 r;
    f32 g;
    f32 b;
    f32 a;

    const static Color RED;
    const static Color GREEN;
    const static Color BLUE;
    const static Color WHITE;
    const static Color BLACK;
    const static Color GREY;
};

#endif //COLOR_H
