#include "PooGame.hpp"
namespace PooGame{
PooGame::PooGame()
:
score(0)
{}

void PooGame::Restart(){
    score = 0;
    
    for (int i = 0; i<NUMBER_OF_POOS; ++i)
        poos[i].Restart();
    
    dude.Restart();
    
    goal.Spawn();
}

void PooGame::UpdateModel(){
    
    double dt = timer.Mark();
    
    dude.Update(wnd, dt);
    for (int i = 0; i<NUMBER_OF_POOS; ++i)
        poos[i].Update(wnd, dt);
    
    
    if(PooCollision()){
        gameState = GameState::End;
        return;
    }
    
    goal.UpdateColor();
    
    if(GoalCollision()){
        goal.Spawn();
        ++score;
    }
    
}
void PooGame::ComposeFrame(){
    goal.Draw(gfx);
    dude.Draw(gfx);
    for (int i = 0; i<NUMBER_OF_POOS; ++i)
        poos[i].Draw(gfx);
    DrawScore();
    
}

bool PooGame::PooCollision() const{
    for (int i = 0; i<NUMBER_OF_POOS; ++i)
        if(dude.GetRect().IsCollideRect(poos[i].GetRect()))
            return true;
    return false;
}

bool PooGame::GoalCollision() const{
    return dude.GetRect().IsCollideRect(goal.GetRect());
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
