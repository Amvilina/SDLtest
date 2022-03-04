#pragma once
#include "Game.hpp"
#include "Poo.hpp"
#include "Surface.hpp"
namespace PooGame {
class Dude{
public:
    Dude();
public:
    void Draw(Graphics& gfx) const;
    void Update(const MainWindow& wnd, double dt);
    
    void Restart();
    Rect GetRect() const;
private:
    Vec2 pos;
    static constexpr double speed = 6.0 * 60.0;
    const double SIZE = 20;
    
    Surface srf = Surface("PooGame/Dude.bmp");
};

}
