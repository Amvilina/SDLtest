#pragma once
#include "Graphics.hpp"
#include <random>

namespace PooGame{

class Goal{
public:
    Goal();
    void Draw(Graphics& gfx) const;
    void Spawn();
    void UpdateColor();
    Rect GetRect() const;
    
private:
    dVec2 pos;
    const int SIZE = 20;
    
    Color color;
};


}
