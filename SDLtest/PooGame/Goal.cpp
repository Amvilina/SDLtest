#include "Goal.hpp"
namespace PooGame{

Goal::Goal():color(255,255,255){Spawn();}

void Goal::Draw(Graphics& gfx) const{
    gfx.DrawRect(pos, SIZE, SIZE, color);
}

void Goal::Spawn(){
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> xDist(0,770);
    std::uniform_int_distribution<int> yDist(0,570);
    
    pos.x = xDist(rng);
    pos.y = yDist(rng);
}

void Goal::UpdateColor(){
    int newR = color.GetR();
    newR -= 2;
    if(newR<0)
        newR = 255;
    
    int newG = color.GetG();
    newG += 3;
    if(newG>255)
        newG = 0;
    
    int newB = color.GetB();
    newB -= 1;
    if(newB<0)
        newB = 255;
    
    color.SetColor(newR, newG, newB);
}

Rect Goal::GetRect() const{return Rect(pos,SIZE,SIZE);}

}
