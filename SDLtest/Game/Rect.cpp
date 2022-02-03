#include "Rect.hpp"

Rect::Rect(){}
Rect::Rect(const Vec2& pos, const Vec2& size):pos(pos), size(size){}
Rect::Rect(const Vec2& pos, double width, double height):pos(pos), size(width, height){}
Rect::Rect(double posx, double posy, double width, double height):pos(posx, posy), size(width, height){}


bool Rect::IsCollide(const Rect &other) const{
    return (pos.x < other.pos.x + other.size.x) && (pos.x+size.x > other.pos.x) &&
           (pos.y < other.pos.y + other.size.y) && (pos.y+size.y > other.pos.y);
}

Rect::Collision Rect::IsCollideWindow(const MainWindow& wnd) const{
    if(pos.x<0)
        return Collision::Left;
    if(pos.y < 0)
        return Collision::Top;
    if(pos.x+size.x-1 >= wnd.GetWidth())
        return Collision::Right;
    if(pos.y+size.y-1 >= wnd.GetHeight())
        return Collision::Bottom;
    return Collision::None;
}

bool Rect::IsCollideMouse(const MainWindow &wnd) const{
    Rect mouse(wnd.mouse.GetPos(),1,1);
    return IsCollide(mouse);
}
