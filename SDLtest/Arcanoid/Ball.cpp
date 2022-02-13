#include "Ball.hpp"

Ball::Ball(const dVec2& center, const dVec2& velocity):center(center), velocity(velocity){}

void Ball::Draw(Graphics &gfx) const{
    gfx.DrawCircle(center, radius, color);
}

void Ball::Update(const MainWindow &wnd, double dt){
    center += velocity.GetNormalized() * speed * dt;
    while(CheckWindowCollisionAndFit(wnd));
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

