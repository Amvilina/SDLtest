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




