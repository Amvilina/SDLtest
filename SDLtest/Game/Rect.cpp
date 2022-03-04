#include "Rect_.hpp"

Rect::Rect(){}
Rect::Rect(const Vec2& pos, double width, double height) : pos(pos), width(width), height(height){}
Rect::Rect(double x, double y, double width, double height) : pos(x, y), width(width), height(height){}

//==============================================

bool Rect::IsCollideRect(const Rect &other) const{
    return 
}

bool Rect::IsContainedIn(const Rect &other) const{
    
}

Rect::Collision Rect::IsCollideWindow(const MainWindow& wnd) const{
    
    
}

bool Rect::IsCollideMouse(const MainWindow &wnd) const{
    Rect mouse(Vec2(wnd.mouse.GetPos()),1,1);
    return IsCollideRect(mouse);
}

double Rect::Left() const{return pos.x;}
double Rect::Right() const{return pos.x + width - 1;}
double Rect::Top() const{return pos.y;}
double Rect::Bottom() const{return pos.y + height - 1;}

Rect Rect::GetExpanded(double offset) const{
    return Rect(pos.x - offset, pos.y - offset, width+offset*2, height+offset*2);
}

Vec2 Rect::GetCenter() const{
    return {pos.x + (width+1)/2, pos.y + (height+1)/2};
}
