#include "Dude.hpp"
#include "SpecialEffects.hpp"

namespace PooGame{

Dude::Dude(){Restart();}

//===============================================

void Dude::Restart(){pos = {390.0,290.0};}

void Dude::Draw(Graphics &gfx) const{
    gfx.DrawSurface(int(pos.x), int(pos.y), srf, SpecialEffects::Chroma( Colors::Magenta ) );
}

void Dude::Update(const MainWindow& wnd, double dt){
    Vec2 posChange;
    if(wnd.mouse.LeftIsPressed()){
        posChange = Vec2(wnd.mouse.GetPos()) - (pos + Vec2(SIZE/2, SIZE/2));
        if (posChange.GetLengthSq() <=3)
            posChange = {0,0};
    }else{
        if (wnd.kbd.IsPressed('w'))
            posChange += {0,-1};
        if (wnd.kbd.IsPressed('s'))
            posChange += {0,1};
        if (wnd.kbd.IsPressed('a'))
            posChange += {-1,0};
        if (wnd.kbd.IsPressed('d'))
            posChange += {1,0};
    }
    
    posChange.Normalize();
    posChange *= speed*dt;
    pos += posChange;
    
    Rect::Collision collision = GetRect().IsCollideWindow(wnd.GetRect());
    switch (collision) {
        case Rect::Collision::None:
            break;
        case Rect::Collision::Top:
            pos.y = 0;
            break;
        case Rect::Collision::Right:
            pos.x = wnd.GetWidth() - SIZE;
            break;
        case Rect::Collision::Bottom:
            pos.y = wnd.GetHeight() - SIZE;
            break;
        case Rect::Collision::Left:
            pos.x = 0;
            break;
        case Rect::Collision::LeftTop:
            pos.y = 0;
            pos.x = 0;
            break;
        case Rect::Collision::RightTop:
            pos.y = 0;
            pos.x = wnd.GetWidth() - SIZE;
            break;
        case Rect::Collision::LeftBottom:
            pos.y = wnd.GetHeight() - SIZE;
            pos.x = 0;
            break;
        case Rect::Collision::RightBottom:
            pos.y = wnd.GetHeight() - SIZE;
            pos.x = wnd.GetWidth() - SIZE;
            break;
    }
}

Rect Dude::GetRect() const {return Rect(pos,SIZE,SIZE);}


}
