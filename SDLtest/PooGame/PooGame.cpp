#include "PooGame.hpp"
namespace PooGame{
PooGame::PooGame()
:
startRect(350,250,100,100),
gameState(GameState::MainMenu),
score(0)
{}

void PooGame::Restart(){
    score = 0;
    gameState = GameState::Game;
    
    for (int i = 0; i<NUMBER_OF_POOS; ++i)
        poos[i].Restart();
    
    dude.Restart();
    
    goal.Spawn();
}

void PooGame::UpdateModel(){
    
    switch (gameState) {
        case GameState::MainMenu:
            if((wnd.mouse.LeftIsPressed() && startRect.IsCollideMouse(wnd)) || wnd.kbd.IsReleased(' ')){
                Restart();
                gameState = GameState::Game;
                timer.Reset();
            }
            break;
            
        case GameState::Pause:
            if(wnd.kbd.IsReleased(' ')){
                gameState = GameState::Game;
                timer.Reset();
            }
            break;
            
        case GameState::Game:
        {
            double dt = timer.Mark();

            dude.Update(wnd, dt);
            for (int i = 0; i<NUMBER_OF_POOS; ++i)
                poos[i].Update(wnd, dt);
            
            if(wnd.kbd.IsReleased(' '))
                gameState = GameState::Pause;
            
            if(PooCollision()){
                gameState = GameState::End;
                break;
            }
            
            goal.UpdateColor();
            
            if(GoalCollision()){
                goal.Spawn();
                ++score;
            }
            
            break;
        }
        case GameState::End:
            if(wnd.kbd.IsReleased(' '))
                gameState = GameState::MainMenu;
            break;
            
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
            goal.Draw(gfx);
            dude.Draw(gfx);
            for (int i = 0; i<NUMBER_OF_POOS; ++i)
                poos[i].Draw(gfx);
            DrawScore();
            break;
    }
}


bool PooGame::PooCollision() const{
    for (int i = 0; i<NUMBER_OF_POOS; ++i)
        if(dude.GetRect().IsCollide(poos[i].GetRect()))
            return true;
    return false;
}

bool PooGame::GoalCollision() const{
    return dude.GetRect().IsCollide(goal.GetRect());
}

void PooGame::DrawScore(){
    int x0 = 10;
    int y0 = 10;
    int width = 3;
    int height = 10;
    int delta = 2;
    
    for (int i = 0; i<score; ++i) {
        gfx.DrawRect(x0 + i*(width+delta), y0, x0+i*(width+delta) + width, y0+height, {50,50,255});
    }
    
    
    
}


}
