#include "Dude.hpp"
namespace PooGame{
Dude::Dude(){Restart();}

//===============================================

void Dude::Restart(){pos = {390.0,290.0};}

void Dude::Draw(Graphics &gfx) const{
    gfx.DrawSurface(pos.x, pos.y, srf, Colors::Magenta);
}

void Dude::Update(const MainWindow& wnd, double dt){
    dVec2 posChange;
    if(wnd.mouse.LeftIsPressed()){
        posChange = wnd.mouse.GetPos() - (pos + dVec2(SIZE/2, SIZE/2));
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
    
    Rect::Collision collision = GetRect().IsCollideWindow(wnd);
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
        case Rect::Collision::TopLeft:
            pos.y = 0;
            pos.x = 0;
            break;
        case Rect::Collision::TopRight:
            pos.y = 0;
            pos.x = wnd.GetWidth() - SIZE;
            break;
        case Rect::Collision::BottomLeft:
            pos.y = wnd.GetHeight() - SIZE;
            pos.x = 0;
            break;
        case Rect::Collision::BottomRight:
            pos.y = wnd.GetHeight() - SIZE;
            pos.x = wnd.GetWidth() - SIZE;
            break;
    }
}

Rect Dude::GetRect() const {return Rect(pos,SIZE,SIZE);}


}
