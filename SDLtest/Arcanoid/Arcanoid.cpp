#include "Arcanoid.hpp"

void Arcanoid::UpdateModel(){
    double dt = timer.Mark();
    ball.Update(wnd, dt);
}

void Arcanoid::ComposeFrame(){
    ball.Draw(gfx);
}
