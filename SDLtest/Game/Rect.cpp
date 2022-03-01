#include "Rect.hpp"

Rect::Rect(){}
Rect::Rect(const dVec2& pos, double width, double height) : pos(pos), width(width), height(height){}
Rect::Rect(double x, double y, double width, double height) : pos(x, y), width(width), height(height){}

//==============================================

bool Rect::IsCollideRect(const Rect &other) const{
    return (pos.x < other.pos.x + other.width) &&
           (pos.x+width > other.pos.x) &&
           (pos.y < other.pos.y + other.height) &&
           (pos.y+height > other.pos.y);
}

bool Rect::IsContainedIn(const Rect &other) const{
    return (pos.x >= other.pos.x) &&
           (pos.y >= other.pos.y) &&
           (pos.x + width <= other.pos.x + other.width) &&
           (pos.y + height <= other.pos.y + other.height);
}

Rect::Collision Rect::IsCollideWindow(const MainWindow& wnd) const{
    
    unsigned char collisionType = 0;
    
    if(pos.x<0)
        collisionType |= 0x0001;
    if(pos.y < 0)
        collisionType |= 0x0002;
    if(pos.x+width-1 >= wnd.GetWidth())
        collisionType |= 0x0004;
    if(pos.y+height-1 >= wnd.GetHeight())
        collisionType |= 0x0008;
    
    switch (collisionType) {
        case 0x0001:
            return Collision::Left;
        case 0x0002:
            return Collision::Top;
        case 0x0002 | 0x0001:
            return Collision::TopLeft;
        case 0x0004:
            return Collision::Right;
        case 0x0002 | 0x0004:
            return Collision::TopRight;
        case 0x0008:
            return Collision::Bottom;
        case 0x0008 | 0x0001:
            return Collision::BottomLeft;
        case 0x0008 | 0x0004:
            return Collision::BottomRight;
        case 0x0000:
        default:
            return Collision::None;
    }
}

bool Rect::IsCollideMouse(const MainWindow &wnd) const{
    Rect mouse(wnd.mouse.GetPos(),1,1);
    return IsCollideRect(mouse);
}

double Rect::Left() const{return pos.x;}
double Rect::Right() const{return pos.x + width - 1;}
double Rect::Top() const{return pos.y;}
double Rect::Bottom() const{return pos.y + height - 1;}

Rect Rect::GetExpanded(double offset) const{
    return Rect(pos.x - offset, pos.y - offset, width+offset*2, height+offset*2);
}

dVec2 Rect::GetCenter() const{
    return {pos.x + (width+1)/2, pos.y + (height+1)/2};
}
