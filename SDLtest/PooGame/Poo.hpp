#pragma once
#include "Game.hpp"
#include "Surface.hpp"
#include "Random.hpp"

namespace PooGame{

class Poo{
public:
    Poo();
public:
    void Draw(Graphics& gfx) const;
    void Update(const MainWindow& wnd, double dt);
    void Restart();
    Rect GetRect() const;
private:
    Vec2 pos;
    Vec2 speed;
    const double SIZE = 24;
     
    static const Surface srf;
};


}
