//
// Created by beyon on 2/24/2024.
//

#include "renderer.h"

namespace Render {
    Renderer::Renderer(BackendType backend_type_)
    : backend_type(backend_type_)
    {
        switch (backend_type)
        {
        case OPENGL:
            renderer_interface = new GlRenderer{};
            break;
        case DIRECTX:
            throw std::runtime_error{"Not implemented! Exiting now..."};
        case VULKAN:
            throw std::runtime_error{"Not implemented! Exiting now..."};
        }
    }

    void Renderer::Init(SDL_Window* window)
    {
        renderer_interface->Init(window);
    }
} // Render