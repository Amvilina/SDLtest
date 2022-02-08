#pragma once
#include "Board.hpp"
namespace SnakeGame{

class Apple{
public:
    Apple();
    void Spawn();
    Point GetPosition() const;
    void Draw(Board& brd) const;
    
private:
    Point loc;
    Color color = {255,0,0};
};



}
