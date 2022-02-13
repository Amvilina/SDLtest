#include "Paddle.hpp"

Paddle::Paddle(const dVec2& pos):rect(pos,width,height){}

void Paddle::Draw(Graphics &gfx) const{
    gfx.DrawRect(rect, colorWings);
    Rect temp = Rect(rect.pos.x + wingsWidth, rect.pos.y, width-wingsWidth*2, height);
    gfx.DrawRect(temp, color);
}

void Paddle::Move(const dVec2 &dir, double dt, const MainWindow &wnd){
    rect.pos += dir.GetNormalized() * dt * speed;
    Rect::Collision collision = rect.IsCollideWindow(wnd);
    if(collision == Rect::Collision::Left)
        rect.pos.x = 0;
    if(collision == Rect::Collision::Right)
        rect.pos.x = wnd.GetWidth()-width;
}

void Paddle::BallCollision(Ball &ball) const{
    if(rect.IsCollide(ball.GetRect()))
        ball.BounceY();
}
