#include "Arcanoid.hpp"

Arcanoid::Arcanoid()
{
    Color colors[verticalNumber] ={
        Colors::Blue,
        Colors::Red,
        Colors::Green,
        Colors::Magenta
    };
    
    for (int y = 0; y<verticalNumber; ++y) {
        for (int x = 0; x<horizontalNumber; ++x) {
            bricks[y*horizontalNumber + x] = Brick(Rect(topLeft + Vec2(x*brickWidth, y*brickHeight), brickWidth, brickHeight), colors[y]);
        }
    }
    
    ball.Restart();
    paddle.Restart();
    for(Brick& b : bricks)
        b.Restart();
}


void Arcanoid::UpdateModel(){
    if(isDead)
        return;
    
    double elapsedTime = timer.Mark();
    while(elapsedTime >= 0.0){
        double dt = std::min(0.005, elapsedTime);
        elapsedTime -= 1.0;
        
        bool touchWalls = ball.Update(wnd, dt);
        if (ball.GetCenter().y == wnd.GetHeight() - ball.GetRadius() - 1){
            isDead = true;
            return;
        }
        
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
}

void Arcanoid::ComposeFrame(){
    ball.Draw(gfx);
    for(const Brick& b : bricks)
        b.Draw(gfx);
    paddle.Draw(gfx);
}
