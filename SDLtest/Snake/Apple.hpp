#pragma once
#include "Board.hpp"
namespace SnakeGame{

class Apple{
public:
    Apple();
    void Spawn();
    iVec2 GetPosition() const;
    void Draw(Board& brd) const;
    
private:
    iVec2 loc;
    Color color = {255,0,0};
};



}
