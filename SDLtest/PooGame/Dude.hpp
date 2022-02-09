#pragma once
#include "Game.hpp"
#include "Poo.hpp"
namespace PooGame {
class Dude{
public:
    
    Dude();
    void Draw(Graphics& gfx) const;
    void Update(const MainWindow& wnd);
    void Restart();
    Rect GetRect() const;
    
private:
    dVec2 pos;
    const int SIZE = 20;
};

}
