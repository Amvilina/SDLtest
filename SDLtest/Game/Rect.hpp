#pragma once
#include "Vec2.hpp"
#include "MainWindow.hpp"

class Rect{

public:
    Rect();
    Rect(const Vec2& pos, const Vec2& size);
    Rect(const Vec2& pos, double width, double height);
    Rect(double posx, double posy, double width, double height);
    
    enum class Collision{
        None,
        Top,
        Right,
        Bottom,
        Left
    };
    
    bool IsCollide(const Rect &other) const;
    Collision IsCollideWindow(const MainWindow& wnd) const;
    bool IsCollideMouse(const MainWindow& wnd) const;

    Vec2 pos;
    Vec2 size;
};