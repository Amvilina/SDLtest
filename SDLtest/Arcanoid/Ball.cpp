#include "Ball.hpp"

void Ball::Restart(){
    center = dVec2(400,550);
    velocity = dVec2(1,-1);
}

void Ball::Draw(Graphics &gfx) const{
    gfx.DrawCircle(center, radius, color);
}

bool Ball::Update(const MainWindow &wnd, double dt){
    center += velocity.GetNormalized() * speed * dt;
    bool flag = false;
    flag = CheckWindowCollisionAndFit(wnd);
    while(CheckWindowCollisionAndFit(wnd));
    return flag;
}

Rect Ball::GetRect() const{
    return Rect(center - dVec2(radius, radius), 2*radius+1, 2*radius+1);
}

dVec2 Ball::GetCenter() const{
    return center;
}

dVec2 Ball::GetVelocity() const{
    return velocity;
}

int Ball::GetRadius() const{
    return radius;
}

void Ball::BounceX(){
    velocity.x = -velocity.x;
}

void Ball::BounceY(){
    velocity.y = -velocity.y;
}

bool Ball::CheckWindowCollisionAndFit(const MainWindow& wnd){
    Rect rect = GetRect();
    Rect::Collision collision = rect.IsCollideWindow(wnd);
    
    if(collision == Rect::Collision::None)
        return false;
    
    if (collision == Rect::Collision::Left) {
        center.x = radius;
        BounceX();
    }
    
    if (collision == Rect::Collision::Top) {
        center.y = radius;
        BounceY();
    }
    
    if (collision == Rect::Collision::Right) {
        center.x = wnd.GetWidth() - radius - 1;
        BounceX();
    }
        
    if (collision == Rect::Collision::Bottom) {
        center.y = wnd.GetHeight() - radius - 1;
        BounceY();
    }
    return true;
}

