#include "Goal.hpp"
namespace PooGame{

Goal::Goal():color(255,255,255){Spawn();}

void Goal::Draw(Graphics& gfx) const{
    gfx.DrawRectDim(pos, SIZE, SIZE, color);
}

void Goal::Spawn(){
    Random rng;
    
    pos.x = rng.GetInt(0, 780);
    pos.y = rng.GetInt(0, 580);
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
