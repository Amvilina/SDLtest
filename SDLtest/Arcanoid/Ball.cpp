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
    
    Rect::Collision collision = GetRect().IsCollideWindow(wnd);
    switch (collision) {
        case Rect::Collision::None:
            return false;
        case Rect::Collision::Top:
            center.y = radius;
            velocity.y = -velocity.y;
            break;
        case Rect::Collision::Right:
            center.x = wnd.GetWidth() - radius - 1;
            velocity.x = -velocity.x;
            break;
        case Rect::Collision::Bottom:
            center.y = wnd.GetHeight() - radius - 1;
            velocity.y = -velocity.y;
            break;
        case Rect::Collision::Left:
            center.x = radius;
            velocity.x = -velocity.x;
            break;
        case Rect::Collision::TopLeft:
            center.y = radius;
            velocity.y = -velocity.y;
            center.x = radius;
            velocity.x = -velocity.x;
            break;
        case Rect::Collision::TopRight:
            center.y = radius;
            velocity.y = -velocity.y;
            center.x = wnd.GetWidth() - radius - 1;
            velocity.x = -velocity.x;
            break;
        case Rect::Collision::BottomLeft:
            center.y = wnd.GetHeight() - radius - 1;
            velocity.y = -velocity.y;
            center.x = radius;
            velocity.x = -velocity.x;
            break;
        case Rect::Collision::BottomRight:
            center.y = wnd.GetHeight() - radius - 1;
            velocity.y = -velocity.y;
            center.x = wnd.GetWidth() - radius - 1;
            velocity.x = -velocity.x;
            break;
    }
    return true;
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

