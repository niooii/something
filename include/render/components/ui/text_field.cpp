//
// Created by beyon on 2/19/2024.
//

#include "text_field.h"

namespace Render::UI
{
    void TextField::HandleKeypress(Key key)
    {
        if (key == Key::KEY_BACKSPACE)
        {
            this->string_.pop_back();
        }
    }
}
