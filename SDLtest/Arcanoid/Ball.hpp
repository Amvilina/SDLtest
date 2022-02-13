#pragma once
#include "Graphics.hpp"

class Ball{
public:
    Ball();
    void Draw(Graphics& gfx) const;
    void Update(const MainWindow& wnd, double dt);
    
    Rect GetRect() const;
    
private:
    dVec2 center;
    dVec2 velocity;
    
    static constexpr int radius = 6;
    static constexpr Color color = Colors::Yellow;
    
    bool CheckWindowCollisionAndFit(const MainWindow& wnd);
};
