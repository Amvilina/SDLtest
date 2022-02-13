#include "Rect.hpp"

Rect::Rect(){}
Rect::Rect(const dVec2& pos, double width, double height):pos(pos), width(width), height(height){}
Rect::Rect(double x, double y, double width, double height):pos(x, y), width(width), height(height){}

bool Rect::IsCollide(const Rect &other) const{
    return (pos.x < other.pos.x + other.width) && (pos.x+width > other.pos.x) &&
           (pos.y < other.pos.y + other.height) && (pos.y+height > other.pos.y);
}

Rect::Collision Rect::IsCollideWindow(const MainWindow& wnd) const{
    if(pos.x<0)
        return Rect::Collision::Left;
    if(pos.y < 0)
        return Rect::Collision::Top;
    if(pos.x+width-1 >= wnd.GetWidth())
        return Rect::Collision::Right;
    if(pos.y+height-1 >= wnd.GetHeight())
        return Rect::Collision::Bottom;
    return Rect::Collision::None;
}

bool Rect::IsCollideMouse(const MainWindow &wnd) const{
    Rect mouse(wnd.mouse.GetPos(),1,1);
    return IsCollide(mouse);
}

Rect Rect::GetExpanded(double offset) const{
    return Rect(pos.x - offset, pos.y - offset, width+offset*2, height+offset*2);
}
