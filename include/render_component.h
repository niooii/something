#ifndef SDLGAMEFRAMEWORK_RENDER_COMPONENT_H
#define SDLGAMEFRAMEWORK_RENDER_COMPONENT_H


class RenderComponent {
public:
    virtual void Draw() = 0;

protected:
    void DrawPixel(int x, int y, int z);
    void DrawTexture(const char* texture_id);
};


#endif