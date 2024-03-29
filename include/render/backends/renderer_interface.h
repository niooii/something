//
// Created by beyon on 2/24/2024.
//

#ifndef RENDERER_INTERFACE_H
#define RENDERER_INTERFACE_H
#include <SDL_video.h>

#include "geometry/rect.h"
#include "math/vec2.h"

#include "types.h"
#include "window.h"
#include "render/color.h"

namespace Render
{
    using Math::Vec2, Geometry::Point, Geometry::Rect;
    class RendererInterface
    {
    protected:
        Window* window_{nullptr};

    public:
        explicit RendererInterface(Window* window) : window_{window} {}

        // Inits renderer w the window pointer
        // maybe just use the constructor for this man.
        virtual void SetWindow(Window* window) = 0;

        // Specific draw methods for each implemented backend type
        virtual void Clear(const Color& color) = 0;
        virtual void Present() = 0;
        virtual void SetViewportSize(Vec2 size) = 0;
        virtual void DrawRect(Rect rect) = 0;
        virtual void DrawText() = 0;
    };
}

#endif //RENDERER_INTERFACE_H
