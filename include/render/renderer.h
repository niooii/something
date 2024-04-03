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
        Window* active_window_;

    public:
        explicit Renderer(Window* window, BackendType backend_type_);

        inline void Clear(const Color& color) const
        {
            renderer_interface->Clear(color);
        }

        inline void Present() const
        {
            renderer_interface->Present();
        }

        inline void DrawTest() const
        {
            renderer_interface->DrawRect(Rect{1, 1, 2}, Color::GREY);
        }
    };
} // Render

#endif //RENDERER_H
