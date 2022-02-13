#include "Brick.hpp"

Brick::Brick(const Rect& rect, const Color& color):rect(rect), color(color),isDestroyed(false){}

void Brick::Draw(Graphics& gfx) const{
    if(!isDestroyed){
        gfx.DrawRect(rect, Colors::Gray);
        gfx.DrawRect(rect.GetExpanded(-1), color);
    }
}

Rect Brick::GetRect() const{
    return rect;
}

bool Brick::BallCollision(Ball& ball){
    if(!isDestroyed && rect.IsCollide(ball.GetRect())){
        isDestroyed = true;
        ball.BounceY();
        return true;
    }
    return false;
}
