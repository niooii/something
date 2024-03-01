//
// Created by beyon on 2/19/2024.
//

#ifndef CLICKABLE_COMPONENT_H
#define CLICKABLE_COMPONENT_H
#include <functional>

#include "render_component.h"

namespace Render
{
    class ClickableComponent : public RenderComponent
    {
    protected:
        std::function<void()> on_press();
        std::function<void()> on_release();

    public:
        // Accessors


        // Other
        virtual void OnClick() = 0;
    };
}

#endif //CLICKABLE_COMPONENT_H
