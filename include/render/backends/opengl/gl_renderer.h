//
// Created by beyon on 2/25/2024.
//

#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

#include "render/backends/renderer_interface.h"

#include <glad/glad.h>
#include "types.h"

namespace Render
{
    class GlRenderer : public RendererInterface
    {
    protected:
        std::optional<SDL_GLContext> gl_context_{};

    public:
        GlRenderer();
        // ~GlRenderer();

        void SetWindow(SDL_Window* window) override;
        void Clear(const Color& color) override;
        void Present() override;
        void SetViewportSize(Vec2 size) override;
        void DrawRectangle(Rect rect) override;
        void DrawText() override;
    };
} // Render

#endif //OPENGL_RENDERER_H
