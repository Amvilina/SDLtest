#include "Paddle.hpp"

Paddle::Paddle(const dVec2& pos):rect(pos,width,height){}

void Paddle::Draw(Graphics &gfx) const{
    gfx.DrawRect(rect, colorWings);
    Rect temp = Rect(rect.pos.x + wingsWidth, rect.pos.y, width-wingsWidth*2, height);
    gfx.DrawRect(temp, color);
}

void Paddle::Move(const dVec2 &dir, double dt, const MainWindow &wnd){
    rect.pos += dir.GetNormalized() * dt * speed;
    Rect::Collision collision = rect.IsCollideWindow(wnd);
    if(collision == Rect::Collision::Left)
        rect.pos.x = 0;
    if(collision == Rect::Collision::Right)
        rect.pos.x = wnd.GetWidth()-width;
}

void Paddle::BallCollision(Ball &ball) const{
    dVec2 ballCenter = ball.GetCenter();
    dVec2 ballVel = ball.GetVelocity();
    Rect ballRect = ball.GetRect();
    int ballRadius = ball.GetRadius();
    
    dVec2 rightBottom = dVec2(rect.pos.x + rect.width-1, rect.pos.y + rect.height-1);
    dVec2 rightTop = dVec2(rect.pos.x + rect.width-1, rect.pos.y);
    dVec2 leftBottom = dVec2(rect.pos.x, rect.pos.y + rect.height-1);
    dVec2 leftTop = dVec2(rect.pos.y, rect.pos.y);
    
    //bottom / top
    if((rect.IsCollide(ballRect)) && (ballCenter.x >= rect.pos.x) && (ballCenter.x <= rightBottom.x)){
        ball.BounceY();
        return;
    }
    
    //left / right
    if((rect.IsCollide(ballRect)) && (ballCenter.y >= rect.pos.y) && (ballCenter.y <= rightBottom.y)){
        ball.BounceX();
        return;
    }
    
    //right bottom
    dVec2 rbDist = rightBottom - ballCenter;
    if (rbDist.GetLengthSq() <= ballRadius*ballRadius) {
        if(ballVel.x >= 0.0){
            ball.BounceY();
            return;
        }
        if(ballVel.y >= 0.0){
            ball.BounceX();
            return;
        }
        ball.BounceY();
        ball.BounceX();
        return;
    }
    
    //right top
    dVec2 rtDist = rightTop - ballCenter;
    if (rtDist.GetLengthSq() <= ballRadius*ballRadius) {
        if(ballVel.x >= 0.0){
            ball.BounceY();
            return;
        }
        if(ballVel.y <= 0.0){
            ball.BounceX();
            return;
        }
        ball.BounceY();
        ball.BounceX();
        return;
    }
    
    //left bottom
    dVec2 lbDist = leftBottom - ballCenter;
    if (lbDist.GetLengthSq() <= ballRadius*ballRadius) {
        if(ballVel.x <= 0.0){
            ball.BounceY();
            return;
        }
        if(ballVel.y >= 0.0){
            ball.BounceX();
            return;
        }
        ball.BounceY();
        ball.BounceX();
        return;
    }
    
    //left top
    dVec2 ltDist = leftTop - ballCenter;
    if (ltDist.GetLengthSq() <= ballRadius*ballRadius) {
        if(ballVel.x <= 0.0){
            ball.BounceY();
            return;
        }
        if(ballVel.y <= 0.0){
            ball.BounceX();
            return;
        }
        ball.BounceY();
        ball.BounceX();
        return;
    }
}
