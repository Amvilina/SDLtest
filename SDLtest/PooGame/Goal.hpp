#pragma once
#include "Graphics.hpp"
#include "Random.hpp"

namespace PooGame{

class Goal{
public:
    Goal();
public:
    void Draw(Graphics& gfx) const;
    void Spawn();
    void UpdateColor();
    Rect GetRect() const;
private:
    Vec2 pos;
    const double SIZE = 20.0;
    
    Color color;
    
    bool isUp = true;
};


}
