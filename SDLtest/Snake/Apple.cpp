#include "Apple.hpp"
#include <random>
#include <ctime>
namespace SnakeGame{

Apple::Apple(){
    Spawn();
}

Point Apple::GetPosition() const{
    return loc;
}

void Apple::Spawn(){
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> xDist(0,Board::GetWidth()-1);
    std::uniform_int_distribution<int> yDist(0,Board::GetHeight()-1);
    
    loc.x = xDist(rng);
    loc.y = yDist(rng);
}

void Apple::Draw(Board &brd) const{
    brd.DrawCell(loc, color);
}


}
