//
// Created by beyon on 2/25/2024.
//

#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

#include "render/backends/renderer_interface.h"

#include <glad/glad.h>

namespace Render
{
    class GlRenderer : public RendererInterface
    {
    private:

    public:
        GlRenderer(SDL_Window* window);
    };
} // Render

#endif //OPENGL_RENDERER_H
