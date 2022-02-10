#pragma once
#include "Game.hpp"
#include "Random.hpp"

namespace PooGame{

class Poo{
public:
    Poo();
    void Draw(Graphics& gfx) const;
    void Update(const MainWindow& wnd, double dt);
    void Restart();
    Rect GetRect() const;
    
private:
    dVec2 pos;
    dVec2 speed;
    const int SIZE = 24;
};

}
