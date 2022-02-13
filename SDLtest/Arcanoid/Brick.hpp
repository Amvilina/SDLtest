#pragma once
#include "Graphics.hpp"

class Brick{
public:
    Brick() = default;
    Brick(const Rect& rect, const Color& color);
    void Draw(Graphics& gfx) const;
    void Destroy();
    Rect GetRect() const;
    
private:
    Rect rect;
    Color color;
    
    bool isDestroyed;
};
