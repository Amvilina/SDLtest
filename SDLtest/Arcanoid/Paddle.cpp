#include "Paddle.hpp"

void Paddle::Restart(){
    isCooldown = false;
    rect = Rect( Vec2{360,570} , width,height);
}

void Paddle::Draw(Graphics &gfx) const{
    gfx.DrawRect(RectI(rect), colorWings);
    Rect temp = Rect( Vec2{ rect.pos.x + wingsWidth, rect.pos.y } , width-wingsWidth*2, height);
    gfx.DrawRect(RectI(temp), color);
}

void Paddle::Move(const Vec2 &dir, double dt, const MainWindow &wnd){
    rect.pos += dir.GetNormalized() * dt * speed;
    Rect::Collision collision = rect.IsCollideWindow(wnd.GetRect());
    if(collision == Rect::Collision::Left)
        rect.pos.x = 0;
    if(collision == Rect::Collision::Right)
        rect.pos.x = wnd.GetWidth()-width;
}

void Paddle::BallCollision(Ball &ball){
    if(isCooldown)
        return;
    Vec2 ballCenter = ball.GetCenter();
    Vec2 ballVel = ball.GetVelocity();
    Rect ballRect = ball.GetRect();
    int ballRadius = ball.GetRadius();
    
    Vec2 rightBottom = Vec2(rect.pos.x + rect.width-1, rect.pos.y + rect.height-1);
    Vec2 rightTop = Vec2(rect.pos.x + rect.width-1, rect.pos.y);
    Vec2 leftBottom = Vec2(rect.pos.x, rect.pos.y + rect.height-1);
    Vec2 leftTop = Vec2(rect.pos.x, rect.pos.y);
    
    //bottom / top
    if((rect.IsCollideRect(ballRect)) && (ballCenter.x >= rect.pos.x) && (ballCenter.x <= rightBottom.x)){
        ball.BounceY();
        isCooldown = true;
        return;
    }
    
    //left / right
    if((rect.IsCollideRect(ballRect)) && (ballCenter.y >= rect.pos.y) && (ballCenter.y <= rightBottom.y)){
        ball.BounceX();
        isCooldown = true;
        return;
    }
    
    //right bottom
    Vec2 rbDist = rightBottom - ballCenter;
    if (rbDist.GetLengthSq() <= ballRadius*ballRadius) {
        if(ballVel.x >= 0.0){
            ball.BounceY();
            isCooldown = true;
            return;
        }
        if(ballVel.y >= 0.0){
            ball.BounceX();
            isCooldown = true;
            return;
        }
        ball.BounceY();
        ball.BounceX();
        isCooldown = true;
        return;
    }
    
    //right top
    Vec2 rtDist = rightTop - ballCenter;
    if (rtDist.GetLengthSq() <= ballRadius*ballRadius) {
        if(ballVel.x >= 0.0){
            ball.BounceY();
            isCooldown = true;
            return;
        }
        if(ballVel.y <= 0.0){
            ball.BounceX();
            isCooldown = true;
            return;
        }
        ball.BounceY();
        ball.BounceX();
        isCooldown = true;
        return;
    }
    
    //left bottom
    Vec2 lbDist = leftBottom - ballCenter;
    if (lbDist.GetLengthSq() <= ballRadius*ballRadius) {
        if(ballVel.x <= 0.0){
            ball.BounceY();
            isCooldown = true;
            return;
        }
        if(ballVel.y >= 0.0){
            ball.BounceX();
            isCooldown = true;
            return;
        }
        ball.BounceY();
        ball.BounceX();
        isCooldown = true;
        return;
    }
    
    //left top
    Vec2 ltDist = leftTop - ballCenter;
    if (ltDist.GetLengthSq() <= ballRadius*ballRadius) {
        if(ballVel.x <= 0.0){
            ball.BounceY();
            isCooldown = true;
            return;
        }
        if(ballVel.y <= 0.0){
            ball.BounceX();
            isCooldown = true;
            return;
        }
        ball.BounceY();
        ball.BounceX();
        isCooldown = true;
        return;
    }
}

void Paddle::ResetCooldown(){
    isCooldown = false;
}
