#pragma once
#include "dVec2.hpp"
#include "MainWindow.hpp"

class Rect{
public:
    enum class Collision{
        None,
        Top,
        Right,
        Bottom,
        Left,
        TopRight,
        TopLeft,
        BottomRight,
        BottomLeft
    };
public:
    Rect();
    Rect(const dVec2& pos, double width, double height);
    Rect(double x, double y, double width, double height);
public:
    bool IsCollideRect(const Rect &other) const;
    bool IsContainedIn(const Rect &other) const;
    Collision IsCollideWindow(const MainWindow& wnd) const;
    bool IsCollideMouse(const MainWindow& wnd) const;

    double Left() const;
    double Right() const;
    double Top() const;
    double Bottom() const;
    
    Rect GetExpanded(double offset) const;
    dVec2 GetCenter() const;
public:
    dVec2 pos;
    double width;
    double height;
};
