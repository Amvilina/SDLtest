#include "Rect.hpp"

Rect::Rect(){}
Rect::Rect(const Vec2& pos, const Vec2& size):pos(pos), size(size){}
Rect::Rect(double posx, double posy, double width, double height):pos(posx, posy), size(width, height){}

bool Rect::IsCollide(const Rect &other) const{
    return (pos.x < other.pos.x + other.size.x) && (pos.x+size.x > other.pos.x) &&
           (pos.y < other.pos.y + other.size.y) && (pos.y+size.y > other.pos.y);
}

bool Rect::IsCollideWindow(const MainWindow& wnd) const{
    return (pos.x < 0) || (pos.y < 0) || (pos.x+size.x-1 >= wnd.GetWidth()) || (pos.y+size.y-1 >= wnd.GetHeight());
}
