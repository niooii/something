//
// Created by niooi on 3/5/24.
//

#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H
#include "base_component.h"

namespace Render
{
    class SpriteComponent : public RenderComponent
    {
    protected:


    public:
        // Accessors


        // Other
        virtual void OnClick() = 0;
    };
}

#endif //SPRITE_COMPONENT_H
