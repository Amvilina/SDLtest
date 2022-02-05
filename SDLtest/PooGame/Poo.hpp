#pragma once
#include "Game.hpp"
namespace PooGame{

class Poo{
public:
    Poo();
    void Draw(Graphics& gfx) const;
    void Update(const MainWindow& wnd);
    void Restart();
    Rect GetRect() const;
    
private:
    Vec2 pos;
    Vec2 speed;
    static constexpr int SIZE = 40;
};
}
