#pragma once
#include "Game.hpp"
#include "Poo.hpp"
namespace PooGame {
class Dude{
public:
    
    Dude();
    void Draw(Graphics& gfx) const;
    void Update(const MainWindow& wnd, double dt);
    
    void Restart();
    Rect GetRect() const;
    
private:
    dVec2 pos;
    static constexpr double speed = 6.0 * 60.0;
    const int SIZE = 20;
    
    
    bool CheckWindowCollisionAndFit(const MainWindow& wnd);
};

}
