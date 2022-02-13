#pragma once
#include "dVec2.hpp"
#include "MainWindow.hpp"

class Rect{

public:
    Rect();
    Rect(const dVec2& pos, double width, double height);
    Rect(double x, double y, double width, double height);
    
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

    Rect GetExpanded(double offset) const;
    
    dVec2 pos;
    double width;
    double height;
};
