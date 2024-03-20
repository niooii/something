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
        u32 vao_quad_{};
        u32 vbo_quad_{};
        u32 ebo_quad_{};

        void InitQuad();

    public:
        GlRenderer(Window* window);
        // ~GlRenderer();

        // replace later its useless
        void SetWindow(Window* window) override;

        // draw functions
        void Clear(const Color& color) override;
        void Present() override;
        void SetViewportSize(Math::Vec2 size) override;
        void DrawRect(Rect rect) override;
        void DrawText() override;
    };
} // Render

#endif //OPENGL_RENDERER_H
