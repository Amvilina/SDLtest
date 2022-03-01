#include "Poo.hpp"
namespace PooGame{

Poo::Poo(){    
    Restart();
}

//======================================

void Poo::Restart(){
    Random rng;
    
    pos = rng.GetDoubleVec2(0.0, 776.0, 0.0, 576.0);
    speed = rng.GetDoubleVec2(-5.5 * 60.0, 5.5 * 60.0);
}

void Poo::Draw(Graphics &gfx) const{
    gfx.DrawSurface(pos.x, pos.y, srf, Colors::White);
}

void Poo::Update(const MainWindow& wnd, double dt){
    pos += speed * dt;
    
    Rect::Collision collision = GetRect().IsCollideWindow(wnd);
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
        case Rect::Collision::TopLeft:
            pos.y = 0;
            speed.y = -speed.y;
            pos.x = 0;
            speed.x = -speed.x;
            break;
        case Rect::Collision::TopRight:
            pos.y = 0;
            speed.y = -speed.y;
            pos.x = wnd.GetWidth() - SIZE;
            speed.x = -speed.x;
            break;
        case Rect::Collision::BottomLeft:
            pos.y = wnd.GetHeight() - SIZE;
            speed.y = -speed.y;
            pos.x = 0;
            speed.x = -speed.x;
            break;
        case Rect::Collision::BottomRight:
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
