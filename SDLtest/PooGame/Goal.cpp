#include "Goal.hpp"
namespace PooGame{

Goal::Goal():color(150,100,100){Spawn();}

//==================================================

void Goal::Draw(Graphics& gfx) const{
    gfx.DrawRect(RectI(GetRect()), color);
}

void Goal::Spawn(){
    Random<double> rng;
    pos = rng.GetVec2(0.0, 780.0, 0.0, 580.0);
}

void Goal::UpdateColor(){
    int newR = color.GetR();
    int newG = color.GetG();
    int newB = color.GetB();
    
    if(isUp){
        newR += 2;
        if(newR >250)
            isUp = false;
    }else{
        newR -= 2;
        if(newR <100)
            isUp = true;
    }
    
    color = Color(newR, newG, newB);
}

Rect Goal::GetRect() const{return Rect(pos,SIZE,SIZE);}

}
