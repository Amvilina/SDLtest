#include "Apple.hpp"

namespace SnakeGame{

iVec2 Apple::GetPosition() const{
    return loc;
}

void Apple::Spawn(){
    Random rng;
    
    loc.x = rng.GetInt(0, Board::GetWidth()-1);
    loc.y = rng.GetInt(0, Board::GetHeight()-1);
}

void Apple::Draw(Board &brd) const{
    brd.DrawCellCircle(loc, color);
}


}
