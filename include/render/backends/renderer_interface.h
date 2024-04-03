//
// Created by beyon on 2/24/2024.
//

#ifndef RENDERER_INTERFACE_H
#define RENDERER_INTERFACE_H
#include <SDL_video.h>

#include "geometry/rect.h"
#include "math/vec2.h"

#include "types.h"
#include "window.h"
#include "../../../shared/transform.h"
#include "render/color.h"

namespace Render
{
    using Math::Vec2, Geometry::Point, Geometry::Rect;
    class RendererInterface
    {
    protected:
        Window* window_{nullptr};

    public:
        explicit RendererInterface(Window* window) : window_{window} {}

        // Inits renderer w the window pointer
        // maybe just use the constructor for this man.
        virtual void SetWindow(Window* window) = 0;

        // Specific draw methods for each implemented backend type
        virtual void Clear(const Color& color) = 0;
        virtual void Present() = 0;
        virtual void SetViewportSize(Vec2 size) = 0;
        virtual void DrawRect(Rect rect, Color color) = 0;
        virtual void DrawString(std::string text, Transform& screen_space_trasform) = 0;

        virtual void LoadTexture(std::string path, std::string id) = 0;
        virtual void DrawTexture(std::string tex_id, Transform& screen_space_trasform) = 0;

        // Other
        // returns false if i/o error OR name already exists.
        virtual bool LoadShader(const char* unique_name, const char* file_path) = 0;
        virtual void UseShader(const char* name) = 0;
    };
}

#endif //RENDERER_INTERFACE_H
