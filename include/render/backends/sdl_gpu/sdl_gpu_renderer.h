//
// Created by beyon on 4/2/2024.
//

#ifndef SDL_GPU_RENDERER_H
#define SDL_GPU_RENDERER_H

#include "render/backends/renderer_interface.h"

#include <SDL_gpu.h>

namespace Render
{
    class SdlGpuRenderer : public RendererInterface
    {
    protected:
        GPU_Target* target_;
    public:
        explicit SdlGpuRenderer(Window* window);

        void SetWindow(Window* window) override;
        void Clear(const Color& color) override;
        void Present() override;
        void SetViewportSize(Vec2 size) override;
        void DrawRect(Rect rect, Color color) override;
        void DrawString(std::string text, Transform& screen_space_trasform) override;
        void LoadTexture(std::string path, std::string id) override;
        void DrawTexture(std::string tex_id, Transform& screen_space_trasform) override;
        bool LoadShader(const char* unique_name, const char* file_path) override;
        void UseShader(const char* name) override;
    };
} // Render

#endif //SDL_GPU_RENDERER_H
