//
// Created by beyon on 2/24/2024.
//

#ifndef RENDERER_INTERFACE_H
#define RENDERER_INTERFACE_H
#include <SDL_video.h>

#include "game/geometry/rect.h"
#include "game/math/vec2.h"

namespace Render
{
    using Math::Vec2, Geometry::Point, Geometry::Rect;
    class RendererInterface
    {
    protected:
        SDL_Window* window{nullptr};

    public:
        // Constructor must initialize window pointer.
        explicit RendererInterface()
        {
        }

        // Inits window ptr specifically for backend type and the renderer itself
        virtual void Init(SDL_Window* window_) = 0;

        // Specific draw methods for each implemented backend type
        virtual void SetViewportSize(Vec2 size) = 0;
        virtual void DrawRectangle(Rect rect) = 0;
    };
}

#endif //RENDERER_INTERFACE_H
