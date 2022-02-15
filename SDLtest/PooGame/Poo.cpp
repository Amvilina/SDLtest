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

void Poo::Draw(Graphics& gfx) const{
    gfx.PutPixel( 14 + pos.x,0 + pos.y,138,77,0 );
    gfx.PutPixel( 7 + pos.x,1 + pos.y,138,77,0 );
    gfx.PutPixel( 13 + pos.x,1 + pos.y,138,77,0 );
    gfx.PutPixel( 20 + pos.x,1 + pos.y,138,77,0 );
    gfx.PutPixel( 6 + pos.x,2 + pos.y,138,77,0 );
    gfx.PutPixel( 13 + pos.x,2 + pos.y,138,77,0 );
    gfx.PutPixel( 20 + pos.x,2 + pos.y,138,77,0 );
    gfx.PutPixel( 6 + pos.x,3 + pos.y,138,77,0 );
    gfx.PutPixel( 6 + pos.x,4 + pos.y,138,77,0 );
    gfx.PutPixel( 14 + pos.x,4 + pos.y,138,77,0 );
    gfx.PutPixel( 21 + pos.x,4 + pos.y,138,77,0 );
    gfx.PutPixel( 7 + pos.x,5 + pos.y,138,77,0 );
    gfx.PutPixel( 13 + pos.x,5 + pos.y,138,77,0 );
    gfx.PutPixel( 21 + pos.x,5 + pos.y,138,77,0 );
    gfx.PutPixel( 7 + pos.x,6 + pos.y,138,77,0 );
    gfx.PutPixel( 20 + pos.x,6 + pos.y,138,77,0 );
    gfx.PutPixel( 6 + pos.x,7 + pos.y,138,77,0 );
    gfx.PutPixel( 14 + pos.x,7 + pos.y,51,28,0 );
    gfx.PutPixel( 15 + pos.x,7 + pos.y,51,28,0 );
    gfx.PutPixel( 20 + pos.x,7 + pos.y,138,77,0 );
    gfx.PutPixel( 12 + pos.x,8 + pos.y,51,28,0 );
    gfx.PutPixel( 13 + pos.x,8 + pos.y,51,28,0 );
    gfx.PutPixel( 14 + pos.x,8 + pos.y,51,28,0 );
    gfx.PutPixel( 7 + pos.x,9 + pos.y,138,77,0 );
    gfx.PutPixel( 11 + pos.x,9 + pos.y,51,28,0 );
    gfx.PutPixel( 12 + pos.x,9 + pos.y,102,57,0 );
    gfx.PutPixel( 13 + pos.x,9 + pos.y,138,77,0 );
    gfx.PutPixel( 14 + pos.x,9 + pos.y,138,77,0 );
    gfx.PutPixel( 15 + pos.x,9 + pos.y,51,28,0 );
    gfx.PutPixel( 21 + pos.x,9 + pos.y,138,77,0 );
    gfx.PutPixel( 10 + pos.x,10 + pos.y,51,28,0 );
    gfx.PutPixel( 11 + pos.x,10 + pos.y,51,28,0 );
    gfx.PutPixel( 12 + pos.x,10 + pos.y,102,57,0 );
    gfx.PutPixel( 13 + pos.x,10 + pos.y,138,77,0 );
    gfx.PutPixel( 14 + pos.x,10 + pos.y,138,77,0 );
    gfx.PutPixel( 15 + pos.x,10 + pos.y,51,28,0 );
    gfx.PutPixel( 20 + pos.x,10 + pos.y,138,77,0 );
    gfx.PutPixel( 9 + pos.x,11 + pos.y,51,28,0 );
    gfx.PutPixel( 10 + pos.x,11 + pos.y,138,77,0 );
    gfx.PutPixel( 11 + pos.x,11 + pos.y,138,77,0 );
    gfx.PutPixel( 12 + pos.x,11 + pos.y,51,28,0 );
    gfx.PutPixel( 13 + pos.x,11 + pos.y,51,28,0 );
    gfx.PutPixel( 14 + pos.x,11 + pos.y,51,28,0 );
    gfx.PutPixel( 15 + pos.x,11 + pos.y,51,28,0 );
    gfx.PutPixel( 16 + pos.x,11 + pos.y,51,28,0 );
    gfx.PutPixel( 9 + pos.x,12 + pos.y,51,28,0 );
    gfx.PutPixel( 10 + pos.x,12 + pos.y,138,77,0 );
    gfx.PutPixel( 11 + pos.x,12 + pos.y,138,77,0 );
    gfx.PutPixel( 12 + pos.x,12 + pos.y,111,62,0 );
    gfx.PutPixel( 13 + pos.x,12 + pos.y,102,57,0 );
    gfx.PutPixel( 14 + pos.x,12 + pos.y,102,57,0 );
    gfx.PutPixel( 15 + pos.x,12 + pos.y,102,57,0 );
    gfx.PutPixel( 16 + pos.x,12 + pos.y,51,28,0 );
    gfx.PutPixel( 9 + pos.x,13 + pos.y,51,28,0 );
    gfx.PutPixel( 10 + pos.x,13 + pos.y,109,61,0 );
    gfx.PutPixel( 11 + pos.x,13 + pos.y,138,77,0 );
    gfx.PutPixel( 12 + pos.x,13 + pos.y,138,77,0 );
    gfx.PutPixel( 13 + pos.x,13 + pos.y,138,77,0 );
    gfx.PutPixel( 14 + pos.x,13 + pos.y,138,77,0 );
    gfx.PutPixel( 15 + pos.x,13 + pos.y,138,77,0 );
    gfx.PutPixel( 16 + pos.x,13 + pos.y,51,28,0 );
    gfx.PutPixel( 5 + pos.x,14 + pos.y,51,28,0 );
    gfx.PutPixel( 7 + pos.x,14 + pos.y,51,28,0 );
    gfx.PutPixel( 8 + pos.x,14 + pos.y,51,28,0 );
    gfx.PutPixel( 9 + pos.x,14 + pos.y,51,28,0 );
    gfx.PutPixel( 10 + pos.x,14 + pos.y,51,28,0 );
    gfx.PutPixel( 11 + pos.x,14 + pos.y,138,77,0 );
    gfx.PutPixel( 12 + pos.x,14 + pos.y,138,77,0 );
    gfx.PutPixel( 13 + pos.x,14 + pos.y,138,77,0 );
    gfx.PutPixel( 14 + pos.x,14 + pos.y,138,77,0 );
    gfx.PutPixel( 15 + pos.x,14 + pos.y,138,77,0 );
    gfx.PutPixel( 16 + pos.x,14 + pos.y,51,28,0 );
    gfx.PutPixel( 4 + pos.x,15 + pos.y,51,28,0 );
    gfx.PutPixel( 5 + pos.x,15 + pos.y,138,77,0 );
    gfx.PutPixel( 6 + pos.x,15 + pos.y,51,28,0 );
    gfx.PutPixel( 7 + pos.x,15 + pos.y,116,65,0 );
    gfx.PutPixel( 8 + pos.x,15 + pos.y,138,77,0 );
    gfx.PutPixel( 9 + pos.x,15 + pos.y,138,77,0 );
    gfx.PutPixel( 10 + pos.x,15 + pos.y,138,77,0 );
    gfx.PutPixel( 11 + pos.x,15 + pos.y,51,28,0 );
    gfx.PutPixel( 12 + pos.x,15 + pos.y,51,28,0 );
    gfx.PutPixel( 13 + pos.x,15 + pos.y,51,28,0 );
    gfx.PutPixel( 14 + pos.x,15 + pos.y,51,28,0 );
    gfx.PutPixel( 15 + pos.x,15 + pos.y,51,28,0 );
    gfx.PutPixel( 16 + pos.x,15 + pos.y,51,28,0 );
    gfx.PutPixel( 17 + pos.x,15 + pos.y,51,28,0 );
    gfx.PutPixel( 18 + pos.x,15 + pos.y,51,28,0 );
    gfx.PutPixel( 1 + pos.x,16 + pos.y,51,28,0 );
    gfx.PutPixel( 2 + pos.x,16 + pos.y,51,28,0 );
    gfx.PutPixel( 3 + pos.x,16 + pos.y,51,28,0 );
    gfx.PutPixel( 4 + pos.x,16 + pos.y,51,28,0 );
    gfx.PutPixel( 5 + pos.x,16 + pos.y,138,77,0 );
    gfx.PutPixel( 6 + pos.x,16 + pos.y,51,28,0 );
    gfx.PutPixel( 7 + pos.x,16 + pos.y,116,65,0 );
    gfx.PutPixel( 8 + pos.x,16 + pos.y,138,77,0 );
    gfx.PutPixel( 9 + pos.x,16 + pos.y,138,77,0 );
    gfx.PutPixel( 10 + pos.x,16 + pos.y,138,77,0 );
    gfx.PutPixel( 11 + pos.x,16 + pos.y,138,77,0 );
    gfx.PutPixel( 12 + pos.x,16 + pos.y,138,77,0 );
    gfx.PutPixel( 13 + pos.x,16 + pos.y,109,61,0 );
    gfx.PutPixel( 14 + pos.x,16 + pos.y,51,28,0 );
    gfx.PutPixel( 15 + pos.x,16 + pos.y,138,77,0 );
    gfx.PutPixel( 16 + pos.x,16 + pos.y,138,77,0 );
    gfx.PutPixel( 17 + pos.x,16 + pos.y,138,77,0 );
    gfx.PutPixel( 18 + pos.x,16 + pos.y,123,69,0 );
    gfx.PutPixel( 19 + pos.x,16 + pos.y,51,28,0 );
    gfx.PutPixel( 0 + pos.x,17 + pos.y,51,28,0 );
    gfx.PutPixel( 1 + pos.x,17 + pos.y,87,49,0 );
    gfx.PutPixel( 2 + pos.x,17 + pos.y,87,49,0 );
    gfx.PutPixel( 3 + pos.x,17 + pos.y,87,49,0 );
    gfx.PutPixel( 4 + pos.x,17 + pos.y,87,49,0 );
    gfx.PutPixel( 5 + pos.x,17 + pos.y,51,28,0 );
    gfx.PutPixel( 6 + pos.x,17 + pos.y,51,28,0 );
    gfx.PutPixel( 7 + pos.x,17 + pos.y,43,24,0 );
    gfx.PutPixel( 8 + pos.x,17 + pos.y,51,28,0 );
    gfx.PutPixel( 9 + pos.x,17 + pos.y,51,28,0 );
    gfx.PutPixel( 10 + pos.x,17 + pos.y,51,28,0 );
    gfx.PutPixel( 11 + pos.x,17 + pos.y,51,28,0 );
    gfx.PutPixel( 12 + pos.x,17 + pos.y,51,28,0 );
    gfx.PutPixel( 13 + pos.x,17 + pos.y,40,22,0 );
    gfx.PutPixel( 14 + pos.x,17 + pos.y,51,28,0 );
    gfx.PutPixel( 15 + pos.x,17 + pos.y,138,77,0 );
    gfx.PutPixel( 16 + pos.x,17 + pos.y,138,77,0 );
    gfx.PutPixel( 17 + pos.x,17 + pos.y,138,77,0 );
    gfx.PutPixel( 18 + pos.x,17 + pos.y,123,69,0 );
    gfx.PutPixel( 19 + pos.x,17 + pos.y,51,28,0 );
    gfx.PutPixel( 0 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 1 + pos.x,18 + pos.y,138,77,0 );
    gfx.PutPixel( 2 + pos.x,18 + pos.y,138,77,0 );
    gfx.PutPixel( 3 + pos.x,18 + pos.y,138,77,0 );
    gfx.PutPixel( 4 + pos.x,18 + pos.y,138,77,0 );
    gfx.PutPixel( 5 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 6 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 7 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 8 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 9 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 10 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 11 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 12 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 13 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 14 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 15 + pos.x,18 + pos.y,138,77,0 );
    gfx.PutPixel( 16 + pos.x,18 + pos.y,138,77,0 );
    gfx.PutPixel( 17 + pos.x,18 + pos.y,138,77,0 );
    gfx.PutPixel( 18 + pos.x,18 + pos.y,123,69,0 );
    gfx.PutPixel( 19 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 20 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 21 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 22 + pos.x,18 + pos.y,51,28,0 );
    gfx.PutPixel( 0 + pos.x,19 + pos.y,51,28,0 );
    gfx.PutPixel( 1 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 2 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 3 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 4 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 5 + pos.x,19 + pos.y,51,28,0 );
    gfx.PutPixel( 6 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 7 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 8 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 9 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 10 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 11 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 12 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 13 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 14 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 15 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 16 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 17 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 18 + pos.x,19 + pos.y,123,69,0 );
    gfx.PutPixel( 19 + pos.x,19 + pos.y,51,28,0 );
    gfx.PutPixel( 20 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 21 + pos.x,19 + pos.y,138,77,0 );
    gfx.PutPixel( 22 + pos.x,19 + pos.y,65,36,0 );
    gfx.PutPixel( 23 + pos.x,19 + pos.y,51,28,0 );
    gfx.PutPixel( 1 + pos.x,20 + pos.y,51,28,0 );
    gfx.PutPixel( 2 + pos.x,20 + pos.y,51,28,0 );
    gfx.PutPixel( 3 + pos.x,20 + pos.y,51,28,0 );
    gfx.PutPixel( 4 + pos.x,20 + pos.y,51,28,0 );
    gfx.PutPixel( 5 + pos.x,20 + pos.y,51,28,0 );
    gfx.PutPixel( 6 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 7 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 8 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 9 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 10 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 11 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 12 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 13 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 14 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 15 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 16 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 17 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 18 + pos.x,20 + pos.y,123,69,0 );
    gfx.PutPixel( 19 + pos.x,20 + pos.y,51,28,0 );
    gfx.PutPixel( 20 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 21 + pos.x,20 + pos.y,138,77,0 );
    gfx.PutPixel( 22 + pos.x,20 + pos.y,65,36,0 );
    gfx.PutPixel( 23 + pos.x,20 + pos.y,51,28,0 );
    gfx.PutPixel( 0 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 1 + pos.x,21 + pos.y,138,77,0 );
    gfx.PutPixel( 2 + pos.x,21 + pos.y,138,77,0 );
    gfx.PutPixel( 3 + pos.x,21 + pos.y,138,77,0 );
    gfx.PutPixel( 4 + pos.x,21 + pos.y,138,77,0 );
    gfx.PutPixel( 5 + pos.x,21 + pos.y,138,77,0 );
    gfx.PutPixel( 6 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 7 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 8 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 9 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 10 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 11 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 12 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 13 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 14 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 15 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 16 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 17 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 18 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 20 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 21 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 22 + pos.x,21 + pos.y,51,28,0 );
    gfx.PutPixel( 0 + pos.x,22 + pos.y,51,28,0 );
    gfx.PutPixel( 1 + pos.x,22 + pos.y,65,36,0 );
    gfx.PutPixel( 2 + pos.x,22 + pos.y,65,36,0 );
    gfx.PutPixel( 3 + pos.x,22 + pos.y,65,36,0 );
    gfx.PutPixel( 4 + pos.x,22 + pos.y,65,36,0 );
    gfx.PutPixel( 5 + pos.x,22 + pos.y,65,36,0 );
    gfx.PutPixel( 6 + pos.x,22 + pos.y,51,28,0 );
    gfx.PutPixel( 1 + pos.x,23 + pos.y,51,28,0 );
    gfx.PutPixel( 2 + pos.x,23 + pos.y,51,28,0 );
    gfx.PutPixel( 3 + pos.x,23 + pos.y,51,28,0 );
    gfx.PutPixel( 4 + pos.x,23 + pos.y,51,28,0 );
    gfx.PutPixel( 5 + pos.x,23 + pos.y,51,28,0 );
    gfx.PutPixel( 6 + pos.x,23 + pos.y,51,28,0 );
    
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
