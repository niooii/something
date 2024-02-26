//
// Created by beyon on 2/24/2024.
//

#ifndef RENDERER_H
#define RENDERER_H
#include <stdexcept>

#include "backends/backend_types.h"
#include "backends/renderer_interface.h"
#include "backends/opengl/gl_renderer.h"

namespace Render
{
    class Renderer
    {
    protected:
        BackendType backend_type;
        RendererInterface* renderer_interface;

    public:
        explicit Renderer(BackendType backend_type_);

        // TODO! make everything in sight inline
        inline void Init(SDL_Window* window)
        {
            renderer_interface->Init(window);
        };

        inline void DrawTest()
        {
            renderer_interface->DrawRectangle(Rect{1, 1, 2});
        }
    };
} // Render

#endif //RENDERER_H
