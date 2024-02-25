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

        void Init(SDL_Window* window);
    };
} // Render

#endif //RENDERER_H
