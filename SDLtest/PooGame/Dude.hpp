#pragma once
#include "Game.hpp"
#include "Poo.hpp"

class Dude{
public:
    Dude(double x, double y);
    void Draw(Graphics& gfx) const;
    void Update(const MainWindow& wnd);
    void TryToEatPoo(Poo& poo);
    
    Vec2 pos;
    static constexpr int SIZE = 20;
};
