#pragma once
#include "Graphics.hpp"

class Ball{
public:
    Ball(const dVec2& center, const dVec2& velocity);
    void Draw(Graphics& gfx) const;
    void Update(const MainWindow& wnd, double dt);
    
    Rect GetRect() const;
    
    void BounceX();
    void BounceY();
    
private:
    dVec2 center;
    dVec2 velocity;
    
    static constexpr int radius = 6;
    static constexpr Color color = Colors::Yellow;
    static constexpr double speed = 5.0 * 60.0;
    
    bool CheckWindowCollisionAndFit(const MainWindow& wnd);
};
