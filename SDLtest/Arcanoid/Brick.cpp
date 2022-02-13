#include "Brick.hpp"

Brick::Brick(const Rect& rect, const Color& color):rect(rect), color(color),isDestroyed(false){}

void Brick::Draw(Graphics& gfx) const{
    if(!isDestroyed){
        gfx.DrawRect(rect, Colors::Gray);
        gfx.DrawRect(rect.GetExpanded(-1), color);
    }
}

Rect Brick::GetRect() const{
    return rect;
}

bool Brick::BallCollisionSides(Ball& ball){
    if(isDestroyed)
        return false;
    
    dVec2 ballCenter = ball.GetCenter();
    Rect ballRect = ball.GetRect();
    
    dVec2 rightBottom = dVec2(rect.pos.x + rect.width-1, rect.pos.y + rect.height-1);
    
    //bottom / top
    if((rect.IsCollide(ballRect)) && (ballCenter.x >= rect.pos.x) && (ballCenter.x <= rightBottom.x)){
        isDestroyed = true;
        ball.BounceY();
        return true;
    }
    
    //left / right
    if((rect.IsCollide(ballRect)) && (ballCenter.y >= rect.pos.y) && (ballCenter.y <= rightBottom.y)){
        isDestroyed = true;
        ball.BounceX();
        return true;
    }
   
    return false;
    
}

bool Brick::BallCollisionCorners(Ball &ball){
    if(isDestroyed)
        return false;
    
    dVec2 ballCenter = ball.GetCenter();
    dVec2 ballVel = ball.GetVelocity();
    int ballRadius = ball.GetRadius();
    
    dVec2 rightBottom = dVec2(rect.pos.x + rect.width-1, rect.pos.y + rect.height-1);
    dVec2 rightTop = dVec2(rect.pos.x + rect.width-1, rect.pos.y);
    dVec2 leftBottom = dVec2(rect.pos.x, rect.pos.y + rect.height-1);
    dVec2 leftTop = dVec2(rect.pos.x, rect.pos.y);
    
    //right bottom
    dVec2 rbDist = rightBottom - ballCenter;
    if (rbDist.GetLengthSq() <= ballRadius*ballRadius) {
        isDestroyed = true;
        if(ballVel.x >= 0.0){
            ball.BounceY();
            return true;
        }
        if(ballVel.y >= 0.0){
            ball.BounceX();
            return true;
        }
        ball.BounceY();
        ball.BounceX();
        return true;
    }
    
    //right top
    dVec2 rtDist = rightTop - ballCenter;
    if (rtDist.GetLengthSq() <= ballRadius*ballRadius) {
        isDestroyed = true;
        if(ballVel.x >= 0.0){
            ball.BounceY();
            return true;
        }
        if(ballVel.y <= 0.0){
            ball.BounceX();
            return true;
        }
        ball.BounceY();
        ball.BounceX();
        return true;
    }
    
    //left bottom
    dVec2 lbDist = leftBottom - ballCenter;
    if (lbDist.GetLengthSq() <= ballRadius*ballRadius) {
        isDestroyed = true;
        if(ballVel.x <= 0.0){
            ball.BounceY();
            return true;
        }
        if(ballVel.y >= 0.0){
            ball.BounceX();
            return true;
        }
        ball.BounceY();
        ball.BounceX();
        return true;
    }
    
    //left top
    dVec2 ltDist = leftTop - ballCenter;
    if (ltDist.GetLengthSq() <= ballRadius*ballRadius) {
        isDestroyed = true;
        if(ballVel.x <= 0.0){
            ball.BounceY();
            return true;
        }
        if(ballVel.y <= 0.0){
            ball.BounceX();
            return true;
        }
        ball.BounceY();
        ball.BounceX();
        return true;
    }
    return false;
    
}
