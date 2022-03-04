#include "Poo.hpp"
#include "SpecialEffects.hpp"

namespace PooGame{

const Surface Poo::srf = Surface("PooGame/Poo.bmp");

Poo::Poo(){    
    Restart();
}

//======================================

void Poo::Restart(){
    Random<double> rng;
    
    pos = rng.GetVec2(0.0, 776.0, 0.0, 576.0);
    speed = rng.GetVec2(-5.5 * 60.0, 5.5 * 60.0);
}

void Poo::Draw(Graphics &gfx) const{
    gfx.DrawSurface( int(pos.x), int(pos.y), srf, SpecialEffects::Chroma( Colors::White ) );
}

void Poo::Update(const MainWindow& wnd, double dt){
    pos += speed * dt;
    
    Rect::Collision collision = GetRect().IsCollideWindow(wnd.GetRect());
    switch (collision) {
        case Rect::Collision::None:
            break;
        case Rect::Collision::Top:
            pos.y = 0;
            speed.y = -speed.y;
            break;
        case Rect::Collision::Right:
            pos.x = wnd.GetWidth() - SIZE;
            speed.x = -speed.x;
            break;
        case Rect::Collision::Bottom:
            pos.y = wnd.GetHeight() - SIZE;
            speed.y = -speed.y;
            break;
        case Rect::Collision::Left:
            pos.x = 0;
            speed.x = -speed.x;
            break;
        case Rect::Collision::LeftTop:
            pos.y = 0;
            speed.y = -speed.y;
            pos.x = 0;
            speed.x = -speed.x;
            break;
        case Rect::Collision::RightTop:
            pos.y = 0;
            speed.y = -speed.y;
            pos.x = wnd.GetWidth() - SIZE;
            speed.x = -speed.x;
            break;
        case Rect::Collision::LeftBottom:
            pos.y = wnd.GetHeight() - SIZE;
            speed.y = -speed.y;
            pos.x = 0;
            speed.x = -speed.x;
            break;
        case Rect::Collision::RightBottom:
            pos.y = wnd.GetHeight() - SIZE;
            speed.y = -speed.y;
            pos.x = wnd.GetWidth() - SIZE;
            speed.x = -speed.x;
            break;
    }
}

Rect Poo::GetRect() const{
    return Rect(pos, SIZE, SIZE);
}

}
