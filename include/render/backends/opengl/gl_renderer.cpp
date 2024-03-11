//
// Created by beyon on 2/25/2024.
//

#include "gl_renderer.h"

namespace Render
{
    // Private initialization stuff
    void GlRenderer::InitQuad()
    {
        f32 vertices[] = {
            0.5f, 0.5f, 0.f, 0.f, 0.f,
            0.5f, -0.5f, 0.f, 0.f, 0.f,
            -0.5f, -0.5f, 0.f, 0.f, 0.f,
            -0.5f, 0.5f, 0.f, 0.f, 0.f,
        };

        u32 indices[] = {
            0, 1, 3,
            1, 2, 3
        };

        glGenVertexArrays(1, &vao_quad_);
        glGenBuffers(1, &vbo_quad_);
        glGenBuffers(1, &ebo_quad_);

        glBindVertexArray(vao_quad_);

        glBindBuffer(GL_ARRAY_BUFFER, vbo_quad_);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_quad_);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // xyz
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,5 * sizeof(f32), nullptr);
        glEnableVertexAttribArray(0);

        // uv
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,5 * sizeof(f32), (void*)(3 * sizeof(f32)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);
    }

    // Constructor
    GlRenderer::GlRenderer(Window* window) : RendererInterface{window}
    {
        gl_context_.emplace(SDL_GL_CreateContext(window->sdl_window()));

        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            spdlog::error("Failed to load OpenGL. The program will exit now...");
            exit(-1);
        }

        this->window_ = window;

        InitQuad();
    }

    void GlRenderer::SetWindow(Window* window)
    {

    }

    void GlRenderer::Clear(const Color& color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void GlRenderer::Present()
    {
        SDL_GL_SwapWindow(window_->sdl_window());
    }

    void GlRenderer::SetViewportSize(const mathfu::Vector<f32, 2> size)
    {
    }

    void GlRenderer::DrawRect(const Rect rect)
    {

        glBindVertexArray(this->vao_quad_);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        glBindVertexArray(0);

        f32 vertices[] = {
            0.5f, 0.5f, 0.f, 0.f, 0.f,
            0.5f, -0.5f, 0.f, 0.f, 0.f,
            -0.5f, -0.5f, 0.f, 0.f, 0.f,
            -0.5f, 0.5f, 0.f, 0.f, 0.f,
        };

        u32 indices[] = {
            0, 1, 3,
            1, 2, 3
        };

    }

    void GlRenderer::DrawText()
    {
    }

} // Render
