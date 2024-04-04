//
// Created by beyon on 2/25/2024.
//

#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

#include "render/backends/renderer_interface.h"

#include <glad/glad.h>
#include "types.h"

// TODO! finish but i dont wanna write opengl man.,
namespace Render
{
    class GlRenderer : public RendererInterface
    {
    protected:
        std::optional<SDL_GLContext> gl_context_{};

    public:
        bool LoadShader(const char *unique_name, const char *file_path) override;

        void UseShader(const char *name) override;

    protected:
        u32 vao_quad_{};
        u32 vbo_quad_{};
        u32 ebo_quad_{};

        void InitQuad();

    public:
        void LoadTexture(std::string path, std::string id) override;
        void DrawTexture(std::string tex_id, Transform& screen_space_trasform) override;

        GlRenderer(Window* window);
        // ~GlRenderer();

        // replace later its useless
        void SetWindow(Window* window) override;

        // draw functions
        void Clear(const Color& color) override;
        void Present() override;
        void SetViewportSize(Math::Vec2 size) override;
        void DrawRect(Rect rect, Color color) override;
        void DrawString(std::string text, Transform& screen_space_trasform) override;
    };
} // Render

#endif //OPENGL_RENDERER_H
