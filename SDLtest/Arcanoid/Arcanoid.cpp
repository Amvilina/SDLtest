#include "Arcanoid.hpp"

Arcanoid::Arcanoid()
:
ball(dVec2(400,500), dVec2(100,-70))
{
    Color colors[verticalNumber] ={
        Colors::Blue,
        Colors::Red,
        Colors::Green,
        Colors::Magenta
    };
    
    for (int y = 0; y<verticalNumber; ++y) {
        for (int x = 0; x<horizontalNumber; ++x) {
            bricks[y*horizontalNumber + x] = Brick(Rect(topLeft + dVec2(x*brickWidth, y*brickHeight), brickWidth, brickHeight), colors[y]);
        }
    }
    
}

void Arcanoid::UpdateModel(){
    double dt = timer.Mark();
    ball.Update(wnd, dt);
}

void Arcanoid::ComposeFrame(){
    ball.Draw(gfx);
    for(const Brick& b : bricks)
        b.Draw(gfx);
}
