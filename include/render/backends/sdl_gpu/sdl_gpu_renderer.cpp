//
// Created by beyon on 4/2/2024.
//

#include "sdl_gpu_renderer.h"

namespace Render
{
    SdlGpuRenderer::SdlGpuRenderer(Window* window) : RendererInterface{window}
    {
        this->window_ = window;

        GPU_SetRequiredFeatures(GPU_FEATURE_BASIC_SHADERS);
        GPU_SetInitWindow(SDL_GetWindowID(window_->sdl_window()));
        target_ = GPU_InitRenderer(GPU_RENDERER_OPENGL_3, window_->width(), window_->height(), GPU_DEFAULT_INIT_FLAGS);

        if (target_->context->context == nullptr)
        {
            spdlog::error("it might seem crazy what im boutta say");
            exit(-1);
        }
    }

    void SdlGpuRenderer::SetWindow(Window* window)
    {
    }

    void SdlGpuRenderer::Clear(const Color& color)
    {
        GPU_ClearColor(target_, color.to_sdl_color());
    }

    void SdlGpuRenderer::Present()
    {
        GPU_Flip(target_);
    }

    void SdlGpuRenderer::SetViewportSize(Vec2 size)
    {
        // GPU_SetViewport(target_, GPU_Rect{0, 0, size.x, size.y});
        GPU_SetWindowResolution(size.x, size.y);
        GPU_ResetProjection(target_);
    }

    void SdlGpuRenderer::DrawRect(Rect rect, Color color)
    {
        GPU_Rectangle2(target_, GPU_Rect{rect.c.x, rect.c.y, rect.w, rect.h}, color.to_sdl_color());
    }

    void SdlGpuRenderer::DrawString(std::string text, Transform& screen_space_trasform)
    {
    }

    void SdlGpuRenderer::LoadTexture(std::string path, std::string id)
    {
    }

    void SdlGpuRenderer::DrawTexture(std::string tex_id, Transform& screen_space_trasform)
    {
    }

    bool SdlGpuRenderer::LoadShader(const char* unique_name, const char* file_path)
    {
        return false;
    }

    void SdlGpuRenderer::UseShader(const char* name)
    {
    }
} // Render
