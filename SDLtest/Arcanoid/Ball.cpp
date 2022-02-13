#include "Ball.hpp"

Ball::Ball()
:
center(100.0, 100.0),
velocity(10, 10)
{}


void Ball::Draw(Graphics &gfx) const{
    gfx.DrawCircle(center, radius, color);
}

void Ball::Update(const MainWindow &wnd, double dt){
    center += velocity*dt;
    while(CheckWindowCollisionAndFit(wnd));
}

Rect Ball::GetRect() const{
    return Rect(center - dVec2(radius, radius), 2*radius+1, 2*radius+1);
}

bool Ball::CheckWindowCollisionAndFit(const MainWindow& wnd){
    Rect rect = GetRect();
    Rect::Collision collision = rect.IsCollideWindow(wnd);
    
    if(collision == Rect::Collision::None)
        return false;
    
    if (collision == Rect::Collision::Left) {
        center.x = radius;
        velocity.x = -velocity.x;
    }
    
    if (collision == Rect::Collision::Top) {
        center.y = radius;
        velocity.y = -velocity.y;
    }
    
    if (collision == Rect::Collision::Right) {
        center.x = wnd.GetWidth() - radius - 1;
        velocity.x = -velocity.x;
    }
        
    if (collision == Rect::Collision::Bottom) {
        center.y = wnd.GetHeight() - radius - 1;
        velocity.y = -velocity.y;
    }
    return true;
}

