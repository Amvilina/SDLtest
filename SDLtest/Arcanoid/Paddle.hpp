#pragma once
#include "Graphics.hpp"
#include "Ball.hpp"

class Paddle{
public:
    void Draw(Graphics& gfx) const;
    void Move(const Vec2& dir, double dt, const MainWindow& wnd);
    void Restart();
    
    void BallCollision(Ball& ball);
    
    void ResetCooldown();
private:
    static constexpr Color color = Colors::White;
    static constexpr Color colorWings = Colors::Red;
    static constexpr int wingsWidth = 5;
    static constexpr int width = 80;
    static constexpr int height = 10;
    static constexpr double speed = 15.0 * 60.0;
    
    Rect rect;
    bool isCooldown = false;
};
