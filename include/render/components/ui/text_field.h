//
// Created by beyon on 2/19/2024.
//

#ifndef TEXT_FIELD_H
#define TEXT_FIELD_H
#include <string>

#include "render/components/clickable_component.h"

namespace Render::UI
{
    // TODO! inheritance or composition which one shall it be
    class TextField : public ClickableComponent
    {
    protected:
        std::string string_{};
        bool is_focused_{false};

    public:
        // Accessors
        inline std::string& GetText()
        {
            return string_;
        }


    };
}

#endif //TEXT_FIELD_H
