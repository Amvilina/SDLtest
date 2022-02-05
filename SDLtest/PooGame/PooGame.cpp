#include "PooGame.hpp"
namespace PooGame{
PooGame::PooGame()
:
startRect(350,250,100,100),
gameState(GameState::MainMenu)
{}

void PooGame::Restart(){
    gameState = GameState::Game;
    
    for (int i = 0; i<NUMBER_OF_POOS; ++i)
        poos[i].Restart();
    
    dude.Restart();
}

void PooGame::UpdateModel(){
    
    switch (gameState) {
        case GameState::MainMenu:
            if(wnd.mouse.LeftIsPressed() && startRect.IsCollideMouse(wnd)){
                Restart();
                gameState = GameState::Game;
            }
            break;
            
        case GameState::Pause:
            if(wnd.kbd.IsReleased(' '))
                gameState = GameState::Game;
            break;
            
        case GameState::Game:
            dude.Update(wnd);
            for (int i = 0; i<NUMBER_OF_POOS; ++i)
                poos[i].Update(wnd);
            
            if(wnd.kbd.IsReleased(' '))
                gameState = GameState::Pause;
            
            for (int i = 0; i<NUMBER_OF_POOS; ++i)
                if(PooCollision(dude,poos[i])){
                    gameState = GameState::End;
                    break;
                }
            break;
            
        case GameState::End:
            if(wnd.kbd.IsReleased(' '))
                gameState = GameState::MainMenu;

    }
    
}
void PooGame::ComposeFrame(){
    
    switch (gameState) {
        case GameState::MainMenu:
            gfx.DrawRect(startRect, {0,200,100});
            break;
        case GameState::Pause:
        case GameState::Game:
        case GameState::End:
            dude.Draw(gfx);
            for (int i = 0; i<NUMBER_OF_POOS; ++i)
                poos[i].Draw(gfx);
            break;
    }
}


bool PooGame::PooCollision(const Dude &dude, const Poo &poo) const{
    return dude.GetRect().IsCollide(poo.GetRect());
}


}
