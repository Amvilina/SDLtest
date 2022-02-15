#pragma once
#include "Graphics.hpp"

class Ball{
public:
    void Draw(Graphics& gfx) const;
    bool Update(const MainWindow& wnd, double dt);
    
    void Restart();
    
    Rect GetRect() const;
    dVec2 GetCenter() const;
    dVec2 GetVelocity() const;
    int GetRadius() const;
    
    void BounceX();
    void BounceY();
    
private:
    dVec2 center;
    dVec2 velocity;
    
    static constexpr int radius = 6;
    static constexpr Color color = Colors::Yellow;
    static constexpr double speed = 10.0 * 60.0;
    
    bool CheckWindowCollisionAndFit(const MainWindow& wnd);
};
