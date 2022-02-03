#include "PooGame.hpp"

PooGame::PooGame()
:
dude(390, 290),
isStart(false)
{}

void PooGame::UpdateModel(){
    if (isStart) {
        dude.Update(wnd);
        
        for (int i = 0; i<NUMBER_OF_POOS; ++i)
            if(!poos[i].isEaten)
                poos[i].Update(wnd);
        
        
        for (int i = 0; i<NUMBER_OF_POOS; ++i)
            if(!poos[i].isEaten)
                dude.TryToEatPoo(poos[i]);
                
                
                
    }else if(wnd.kbd.IsReleased(' '))
            isStart = true;
     
}
void PooGame::ComposeFrame(){
    
    if(isStart){
        dude.Draw(gfx);
        for (int i = 0; i<NUMBER_OF_POOS; ++i)
            if(!poos[i].isEaten)
                poos[i].Draw(gfx);
        
    }
    
}


PooGame::Dude::Dude(double x, double y):pos(x,y){}
void PooGame::Dude::Draw(Graphics& gfx) const{
    gfx.PutPixel( 7 + pos.x,0 + pos.y,0,0,0 );
    gfx.PutPixel( 8 + pos.x,0 + pos.y,0,0,0 );
    gfx.PutPixel( 9 + pos.x,0 + pos.y,0,0,0 );
    gfx.PutPixel( 10 + pos.x,0 + pos.y,0,0,0 );
    gfx.PutPixel( 11 + pos.x,0 + pos.y,0,0,0 );
    gfx.PutPixel( 12 + pos.x,0 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,1 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,1 + pos.y,0,0,0 );
    gfx.PutPixel( 7 + pos.x,1 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,1 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,1 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,1 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,1 + pos.y,254,221,88 );
    gfx.PutPixel( 12 + pos.x,1 + pos.y,254,221,88 );
    gfx.PutPixel( 13 + pos.x,1 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,1 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,2 + pos.y,0,0,0 );
    gfx.PutPixel( 4 + pos.x,2 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 12 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 13 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 14 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 15 + pos.x,2 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,2 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,3 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 5 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 12 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 13 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 14 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 15 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,3 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,4 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 5 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 12 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 13 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 14 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 15 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,4 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 3 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 4 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 12 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 13 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 15 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,6 + pos.y,255,255,255 );
    gfx.PutPixel( 4 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,6 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,6 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,6 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,6 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 11 + pos.x,6 + pos.y,255,255,255 );
    gfx.PutPixel( 12 + pos.x,6 + pos.y,255,255,255 );
    gfx.PutPixel( 13 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 15 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,6 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,6 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 0 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,7 + pos.y,255,255,255 );
    gfx.PutPixel( 3 + pos.x,7 + pos.y,255,255,255 );
    gfx.PutPixel( 4 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 11 + pos.x,7 + pos.y,255,255,255 );
    gfx.PutPixel( 12 + pos.x,7 + pos.y,255,255,255 );
    gfx.PutPixel( 13 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 15 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 19 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 0 + pos.x,8 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,8 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 3 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 4 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 5 + pos.x,8 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,8 + pos.y,0,0,0 );
    gfx.PutPixel( 11 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 12 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 13 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 14 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 15 + pos.x,8 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 19 + pos.x,8 + pos.y,0,0,0 );
    gfx.PutPixel( 0 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 2 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 4 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 12 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 13 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 15 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 19 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 0 + pos.x,10 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 2 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 3 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 5 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 12 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 13 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 14 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 15 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 19 + pos.x,10 + pos.y,0,0,0 );
    gfx.PutPixel( 0 + pos.x,11 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 2 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 3 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 5 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,11 + pos.y,20,14,18 );
    gfx.PutPixel( 8 + pos.x,11 + pos.y,18,11,14 );
    gfx.PutPixel( 9 + pos.x,11 + pos.y,18,12,14 );
    gfx.PutPixel( 10 + pos.x,11 + pos.y,18,12,14 );
    gfx.PutPixel( 11 + pos.x,11 + pos.y,21,13,16 );
    gfx.PutPixel( 12 + pos.x,11 + pos.y,24,11,15 );
    gfx.PutPixel( 13 + pos.x,11 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 15 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 19 + pos.x,11 + pos.y,0,0,0 );
    gfx.PutPixel( 0 + pos.x,12 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 2 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 3 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 5 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,12 + pos.y,23,9,23 );
    gfx.PutPixel( 7 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 8 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 9 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 10 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 11 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 12 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 13 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 14 + pos.x,12 + pos.y,0,0,0 );
    gfx.PutPixel( 15 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 19 + pos.x,12 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,13 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,13 + pos.y,254,221,88 );
    gfx.PutPixel( 3 + pos.x,13 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,13 + pos.y,254,221,88 );
    gfx.PutPixel( 5 + pos.x,13 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 7 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 8 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 9 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 10 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 11 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 12 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 13 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 14 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 15 + pos.x,13 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,13 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,13 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,13 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,14 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,14 + pos.y,254,221,88 );
    gfx.PutPixel( 3 + pos.x,14 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,14 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,14 + pos.y,135,26,68 );
    gfx.PutPixel( 6 + pos.x,14 + pos.y,135,26,68 );
    gfx.PutPixel( 7 + pos.x,14 + pos.y,135,26,68 );
    gfx.PutPixel( 8 + pos.x,14 + pos.y,135,26,68 );
    gfx.PutPixel( 9 + pos.x,14 + pos.y,251,192,224 );
    gfx.PutPixel( 10 + pos.x,14 + pos.y,251,192,224 );
    gfx.PutPixel( 11 + pos.x,14 + pos.y,251,192,224 );
    gfx.PutPixel( 12 + pos.x,14 + pos.y,251,192,224 );
    gfx.PutPixel( 13 + pos.x,14 + pos.y,135,26,68 );
    gfx.PutPixel( 14 + pos.x,14 + pos.y,135,26,68 );
    gfx.PutPixel( 15 + pos.x,14 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,14 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,14 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,14 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,15 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,15 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,15 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,15 + pos.y,135,26,68 );
    gfx.PutPixel( 6 + pos.x,15 + pos.y,135,26,68 );
    gfx.PutPixel( 7 + pos.x,15 + pos.y,135,26,68 );
    gfx.PutPixel( 8 + pos.x,15 + pos.y,251,192,224 );
    gfx.PutPixel( 9 + pos.x,15 + pos.y,251,192,224 );
    gfx.PutPixel( 10 + pos.x,15 + pos.y,251,192,224 );
    gfx.PutPixel( 11 + pos.x,15 + pos.y,251,192,224 );
    gfx.PutPixel( 12 + pos.x,15 + pos.y,251,192,224 );
    gfx.PutPixel( 13 + pos.x,15 + pos.y,251,192,224 );
    gfx.PutPixel( 14 + pos.x,15 + pos.y,135,26,68 );
    gfx.PutPixel( 15 + pos.x,15 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,15 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,15 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,16 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,16 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,16 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,16 + pos.y,135,26,68 );
    gfx.PutPixel( 6 + pos.x,16 + pos.y,135,26,68 );
    gfx.PutPixel( 7 + pos.x,16 + pos.y,135,26,68 );
    gfx.PutPixel( 8 + pos.x,16 + pos.y,251,192,224 );
    gfx.PutPixel( 9 + pos.x,16 + pos.y,251,192,224 );
    gfx.PutPixel( 10 + pos.x,16 + pos.y,251,192,224 );
    gfx.PutPixel( 11 + pos.x,16 + pos.y,251,192,224 );
    gfx.PutPixel( 12 + pos.x,16 + pos.y,251,192,224 );
    gfx.PutPixel( 13 + pos.x,16 + pos.y,251,192,224 );
    gfx.PutPixel( 14 + pos.x,16 + pos.y,135,26,68 );
    gfx.PutPixel( 15 + pos.x,16 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,16 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,16 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 4 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 7 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 8 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 9 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 10 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 11 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 12 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 13 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 15 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,18 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,18 + pos.y,0,0,0 );
    gfx.PutPixel( 7 + pos.x,18 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,18 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,18 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,18 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,18 + pos.y,254,221,88 );
    gfx.PutPixel( 12 + pos.x,18 + pos.y,254,221,88 );
    gfx.PutPixel( 13 + pos.x,18 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,18 + pos.y,0,0,0 );
    gfx.PutPixel( 7 + pos.x,19 + pos.y,0,0,0 );
    gfx.PutPixel( 8 + pos.x,19 + pos.y,0,0,0 );
    gfx.PutPixel( 9 + pos.x,19 + pos.y,0,0,0 );
    gfx.PutPixel( 10 + pos.x,19 + pos.y,0,0,0 );
    gfx.PutPixel( 11 + pos.x,19 + pos.y,0,0,0 );
    gfx.PutPixel( 12 + pos.x,19 + pos.y,0,0,0 );
    
}
void PooGame::Dude::Update(const MainWindow& wnd){
    if (wnd.kbd.IsPressed('w'))
        pos.y -=3;
    if (wnd.kbd.IsPressed('s'))
        pos.y+=3;
    if (wnd.kbd.IsPressed('a'))
        pos.x-=3;
    if (wnd.kbd.IsPressed('d'))
        pos.x+=3;
    
    Rect rect(pos,SIZE,SIZE);
    Rect::Collision collision = rect.IsCollideWindow(wnd);
    
    if(collision == Rect::Collision::None)
        return;
    
    if (collision == Rect::Collision::Left) {
        pos.x = 0;
    }
    
    if (collision == Rect::Collision::Top) {
        pos.y = 0;
    }
    
    if (collision == Rect::Collision::Right) {
        pos.x = wnd.GetWidth() - SIZE;
    }
        
    if (collision == Rect::Collision::Bottom) {
        pos.y = wnd.GetHeight() - SIZE;
    }
}
void PooGame::Dude::TryToEatPoo(Poo &poo){
    Rect rect(pos,SIZE,SIZE);
    if(rect.IsCollide(Rect(poo.pos,Poo::SIZE,Poo::SIZE)))
        poo.isEaten = true;
}



PooGame::Poo::Poo():isEaten(false){
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> xDist(0,770);
    std::uniform_int_distribution<int> yDist(0,570);
    std::uniform_int_distribution<int> Speed(-3,3);
    
    pos.x = xDist(rng);
    pos.y = yDist(rng);
    speed.x = Speed(rng);
    speed.y = Speed(rng);
    
}
void PooGame::Poo::Draw(Graphics& gfx) const{
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
void PooGame::Poo::Update(const MainWindow& wnd){
    pos += speed;
    
    Rect rect(pos,SIZE,SIZE);
    Rect::Collision collision = rect.IsCollideWindow(wnd);
    
    if(collision == Rect::Collision::None)
        return;
    
    if (collision == Rect::Collision::Left) {
        pos.x = 0;
        speed.x = -speed.x;
    }
    
    if (collision == Rect::Collision::Top) {
        pos.y = 0;
        speed.y = -speed.y;
    }
    
    if (collision == Rect::Collision::Right) {
        pos.x = wnd.GetWidth() - SIZE;
        speed.x = -speed.x;
    }
        
    if (collision == Rect::Collision::Bottom) {
        pos.y = wnd.GetHeight() - SIZE;
        speed.y = -speed.y;
    }
}

