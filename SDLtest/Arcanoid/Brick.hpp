#pragma once
#include "Graphics.hpp"
#include "Ball.hpp"

class Brick{
public:
    Brick() = default;
    Brick(const Rect& rect, const Color& color);
    void Draw(Graphics& gfx) const;
    Rect GetRect() const;
    
    bool BallCollision(Ball& ball);
    
private:
    Rect rect;
    Color color;
    
    bool isDestroyed;
};
