#ifndef SDLGAMEFRAMEWORK_RENDER_COMPONENT_H
#define SDLGAMEFRAMEWORK_RENDER_COMPONENT_H


namespace Render
{
    class RenderComponent
    {
    protected:
        bool use_world_coords{false};
        int z_idx{0};

    public:
        // Accessors
        inline int z_index() const { return z_idx; }

        // Other
        virtual void Draw() = 0;
    };
}


#endif
