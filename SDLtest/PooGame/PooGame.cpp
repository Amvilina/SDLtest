#include "PooGame.hpp"
#include "SpecialEffects.hpp"

namespace PooGame{

PooGame::PooGame()
{
    Restart();
}

void PooGame::Restart(){
    score = 0;
    
    poos.resize(nPooStart);
    for (int i = 0; i<nPooStart; ++i){
        poos[i].Restart();
    }
    
    dude.Restart();
    
    goal.Spawn();
    
    isDead = false;
    isStart = false;
}

void PooGame::UpdateModel(){
    
    if(!isStart){
        if(wnd.kbd.IsReleased(' '))
            isStart = true;
        return;
    }
        
    if(isDead){
        if(wnd.kbd.IsReleased(' ')){
            Restart();
        }
        return;
    }
    
    
    double dt = timer.Mark();
    dude.Update(wnd, dt);
    for (int i = 0; i<poos.size(); ++i)
        poos[i].Update(wnd, dt);
    
    
    if(PooCollision()){
        isDead = true;
        return;
    }
    
    goal.UpdateColor();
    
    if(GoalCollision()){
        goal.Spawn();
        ++score;
    }
    
    if (wnd.kbd.IsReleased('f')) {
        poos.emplace_back();
        poos[poos.size()-1].Restart();
    }
    
}
void PooGame::ComposeFrame(){
    if(!isStart){
        int x = gfx.GetRect().GetCenter().x - srfStart.GetWidth()/2;
        int y = gfx.GetRect().GetCenter().y - srfStart.GetHeight()/2;
        gfx.DrawSurface(x, y, srfStart, SpecialEffects::Copy());
        return;
    }
    
    goal.Draw(gfx);
    dude.Draw(gfx);
    for (int i = 0; i<poos.size(); ++i)
        poos[i].Draw(gfx);
    DrawScore();
    
    if(isDead){
        int x = gfx.GetRect().GetCenter().x - srfEnd.GetWidth()/2;
        int y = gfx.GetRect().GetCenter().y - srfEnd.GetHeight()/2;
        gfx.DrawSurface(x, y, srfEnd, SpecialEffects::Ghost(0.5, Colors::Black));
    }
    
}

bool PooGame::PooCollision() const{
    for (int i = 0; i<poos.size(); ++i)
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
