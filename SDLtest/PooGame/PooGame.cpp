#include "PooGame.hpp"

PooGame::PooGame()
:
dude(390, 290),
startRect(350,250,100,100),
isStart(false),
isEnd(false)
{}

void PooGame::UpdateModel(){
    if (isStart && !isEnd) {
        dude.Update(wnd);
        
        for (int i = 0; i<NUMBER_OF_POOS; ++i)
            if(!poos[i].isEaten)
                poos[i].Update(wnd);
        
        
        for (int i = 0; i<NUMBER_OF_POOS; ++i)
            if(!poos[i].isEaten)
                dude.TryToEatPoo(poos[i]);
                
            
        isEnd = true;
        for (int i = 0; i<NUMBER_OF_POOS; ++i)
            isEnd = isEnd && poos[i].isEaten;
      
                
    }else if(wnd.mouse.LeftIsPressed() && startRect.IsCollideMouse(wnd))
            isStart = true;
    
    
     
}
void PooGame::ComposeFrame(){
    
    if(isStart){
        dude.Draw(gfx);
        for (int i = 0; i<NUMBER_OF_POOS; ++i)
            if(!poos[i].isEaten)
                poos[i].Draw(gfx);
                
    }else{
        gfx.DrawRect(startRect, {0,200,100});
    }
    
}




