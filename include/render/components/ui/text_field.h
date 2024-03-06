//
// Created by beyon on 2/19/2024.
//

#ifndef TEXT_FIELD_H
#define TEXT_FIELD_H
#include <string>

#include "input/keyboard.h"
#include "render/components/base_component.h"

namespace Render::UI
{
    // TODO! inheritance or composition which one shall it be
    class TextField : public RenderComponent
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

        inline bool IsFocused() const
        {
            return is_focused_;
        };

        // Other
        inline void SetFocused(bool is_focused)
        {
            is_focused_ = is_focused;
        }

        void HandleKeypress(Key key);

    };
}

#endif //TEXT_FIELD_H
