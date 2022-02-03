#pragma once
#include "Game.hpp"

class Poo{
public:
    Poo();
    void Draw(Graphics& gfx) const;
    void Update(const MainWindow& wnd);
    
    Vec2 pos;
    Vec2 speed;
    static constexpr int SIZE = 40;
    bool isEaten;
};
