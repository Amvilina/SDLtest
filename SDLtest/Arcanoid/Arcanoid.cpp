#include "Arcanoid.hpp"

Arcanoid::Arcanoid()
:
ball(dVec2(300 + 24.0,300), dVec2(-300,-300)),
paddle(dVec2(360,560))
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
    
    bool touchWalls = ball.Update(wnd, dt);
    
    if(wnd.kbd.IsPressed('a'))
        paddle.Move({-1,0}, dt, wnd);
    if(wnd.kbd.IsPressed('d'))
        paddle.Move({1,0}, dt, wnd);
    
    bool flag = false;
    for(Brick& b : bricks)
        if(b.BallCollisionSides(ball)){
            flag = true;
            break;
        }
    if(!flag)
        for(Brick& b : bricks)
            if(b.BallCollisionCorners(ball)){
                flag = true;
                break;
            }
        
    if(flag || touchWalls)
        paddle.ResetCooldown();
    
    paddle.BallCollision(ball);
                                                  
}

void Arcanoid::ComposeFrame(){
    ball.Draw(gfx);
    for(const Brick& b : bricks)
        b.Draw(gfx);
    paddle.Draw(gfx);
}
