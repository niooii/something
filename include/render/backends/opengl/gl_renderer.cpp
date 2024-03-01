//
// Created by beyon on 2/25/2024.
//

#include "gl_renderer.h"

namespace Render
{
    GlRenderer::GlRenderer()
    = default;

    void GlRenderer::Init(SDL_Window* window)
    {
        SDL_GL_CreateContext(window);

        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            spdlog::error("Failed to load OpenGL. The program will exit now...");
            exit(-1);
        }



    }

    void GlRenderer::SetViewportSize(Vec2 size)
    {
    }

    void GlRenderer::DrawRectangle(Rect rect)
    {
    }

    void GlRenderer::DrawText()
    {
    }

} // Render
