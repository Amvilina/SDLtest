#pragma once
#include "Board.hpp"
#include "Random.hpp"
namespace SnakeGame{

class Obstacle{
public:
    
    void Draw(Board& brd) const;
    void Spawn();
    iVec2 GetPosition() const;
    
private:
    iVec2 pos;
    Color color = { 200, 200, 200 };
};



}
