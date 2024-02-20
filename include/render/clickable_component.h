//
// Created by beyon on 2/19/2024.
//

#ifndef CLICKABLE_COMPONENT_H
#define CLICKABLE_COMPONENT_H

namespace Render
{
    class ClickableComponent {
    protected:
        bool use_world_coords{false};
        int z_idx{0};

    public:
        // Accessors
        inline int z_index() const { return z_idx; }

        // Other
        virtual void Draw() = 0;
        virtual void OnClick() = 0;
    };
}

#endif //CLICKABLE_COMPONENT_H
