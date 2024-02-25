//
// Created by beyon on 2/24/2024.
//

#ifndef RENDERER_H
#define RENDERER_H
#include <stdexcept>

#include "backends/backend_types.h"
#include "backends/renderer_interface.h"

namespace Render
{
    class Renderer
    {
    protected:
        BackendType backend_type;
        RendererInterface* renderer_backend;

    public:
        Renderer(BackendType backend_type_) : backend_type(backend_type_)
        {
            switch (backend_type)
            {
            case OPENGL:
                throw std::runtime_error{"Not implemented! Exiting now..."};
            case DIRECTX:
                throw std::runtime_error{"Not implemented! Exiting now..."};
            case VULKAN:
                throw std::runtime_error{"Not implemented! Exiting now..."};
            }
        }
    };
} // Render

#endif //RENDERER_H
