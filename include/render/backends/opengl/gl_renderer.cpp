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
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

        window = SDL_CreateWindow(
            "SomeName",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            800,
            800,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
        );

    }

    void GlRenderer::SetViewportSize(Vec2 size)
    {
    }

    void GlRenderer::DrawRectangle(Rect rect)
    {
    }
} // Render
