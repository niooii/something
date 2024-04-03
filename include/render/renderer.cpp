//
// Created by beyon on 2/24/2024.
//

#include "renderer.h"

#include "backends/sdl_gpu/sdl_gpu_renderer.h"

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
        case SDL_GPU:
            renderer_interface = new SdlGpuRenderer{window};
            break;
        case DIRECTX:
            throw std::runtime_error{"Not implemented! Exiting now..."};
        case VULKAN:
            throw std::runtime_error{"Not implemented! Exiting now..."};
        }
    }
} // Render
