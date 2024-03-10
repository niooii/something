//
// Created by beyon on 2/25/2024.
//

#include "gl_renderer.h"

namespace Render
{
    GlRenderer::GlRenderer()
    = default;

    void GlRenderer::SetWindow(SDL_Window* window)
    {
        gl_context_.emplace(SDL_GL_CreateContext(window));

        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            spdlog::error("Failed to load OpenGL. The program will exit now...");
            exit(-1);
        }

        this->window_ = window;
    }

    void GlRenderer::Clear(const Color& color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void GlRenderer::Present()
    {
        SDL_GL_SwapWindow(window_);
    }

    void GlRenderer::SetViewportSize(const Vec2 size)
    {
    }

    void GlRenderer::DrawRectangle(const Rect rect)
    {
    }

    void GlRenderer::DrawText()
    {
    }

} // Render
