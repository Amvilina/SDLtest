#pragma once
#include "Vec2.hpp"
#include "MainWindow.hpp"

class Rect{

public:
    Rect();
    Rect(const Vec2& pos, const Vec2& size);
    Rect(double posx, double posy, double width, double height);
    
    bool IsCollide(const Rect &other) const;
    bool IsCollideWindow(const MainWindow& wnd) const;

    Vec2 pos;
    Vec2 size;
};
