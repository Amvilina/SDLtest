#pragma once
#include "Board.hpp"
#include "Random.hpp"

namespace SnakeGame{

class Apple{
public:
    void Spawn();
    iVec2 GetPosition() const;
    void Draw(Board& brd) const;
    
private:
    iVec2 loc;
    static constexpr Color color = Colors::Red;
};



}
