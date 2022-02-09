#include "Obstacle.hpp"
namespace SnakeGame{

void Obstacle::Draw(Board &brd) const{
    brd.DrawCell(pos,color);
}

void Obstacle::Spawn(){
    Random rng;
    pos.x = rng.GetInt(0, Board::GetWidth()-1);
    pos.y = rng.GetInt(0, Board::GetHeight()-1);
}

iVec2 Obstacle::GetPosition() const{return pos;}


}
