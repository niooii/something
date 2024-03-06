#ifndef SDLGAMEFRAMEWORK_RENDER_COMPONENT_H
#define SDLGAMEFRAMEWORK_RENDER_COMPONENT_H

#include "../../../shared/transform.h"
#include "render/renderer.h"

namespace Render
{
    class RenderComponent
    {
    protected:
        i32 z_idx{0};
        bool is_clickable_{false};

        // callbacks
        std::optional<std::function<void()>> on_press{};
        std::optional<std::function<void(f32 delta_time)>> on_hold{};
        std::optional<std::function<void()>> on_release{};

    public:
        // Accessors
        inline i32 z_index() const { return z_idx; }

        // Other
        // TRANSFORM CENTER COORDINATES ARE IN SCREEN SPACE.
        Transform transform{};
        virtual void Draw(Renderer* renderer) = 0;

        // callback stuff
        inline void DoOnPress() const
        {
            if (on_press.has_value())
            {
                on_press.value()();
            }
        };
        inline void DoOnHold(f32 delta_time) const
        {
            if (on_hold.has_value())
            {
                on_hold.value()(delta_time);
            }
        };
        inline void DoOnRelease() const
        {
            if (on_release.has_value())
            {
                on_release.value()();
            }
        };

        inline void BindOnPress(const std::function<void()>& f)
        {
            on_press.emplace(f);
        };
        inline void BindOnHold(const std::function<void(f32 delta_time)>& f)
        {
            on_hold.emplace(f);
        }
        inline void BindOnRelease(const std::function<void()>& f)
        {
            on_release.emplace(f);
        }
    };
}


#endif
