//
// Created by beyon on 2/24/2024.
//

#include "renderer.h"

namespace Render
{
    Renderer::Renderer(Window* window, BackendType backend_type_)
        : backend_type{backend_type_}, active_window_{window}
    {
        switch (backend_type)
        {
        case OPENGL:
            renderer_interface = new GlRenderer{window};
            break;
        case DIRECTX:
            throw std::runtime_error{"Not implemented! Exiting now..."};
        case VULKAN:
            throw std::runtime_error{"Not implemented! Exiting now..."};
        }
    }
} // Render
