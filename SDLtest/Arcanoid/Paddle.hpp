#pragma once
#include "Graphics.hpp"

class Paddle{
public:
    Paddle(const dVec2& pos);
    void Draw(Graphics& gfx) const;
    void Move(const dVec2& dir, double dt, const MainWindow& wnd);
    
private:
    static constexpr Color color = Colors::White;
    static constexpr Color colorWings = Colors::Red;
    static constexpr int wingsWidth = 5;
    static constexpr int width = 80;
    static constexpr int height = 25;
    static constexpr double speed = 10.0 * 60.0;
    
    Rect rect;
};
