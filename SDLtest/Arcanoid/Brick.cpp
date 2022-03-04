#include "Brick.hpp"

void Brick::Restart(){isDestroyed = false;}

Brick::Brick(const Rect& rect, const Color& color):rect(rect), color(color),isDestroyed(false){}

void Brick::Draw(Graphics& gfx) const{
    if(!isDestroyed){
        gfx.DrawRect(RectI(rect), Colors::Gray);
        gfx.DrawRect(RectI(rect.GetExpanded(-1)), color);
    }
}

Rect Brick::GetRect() const{
    return rect;
}

bool Brick::BallCollisionSides(Ball& ball){
    if(isDestroyed)
        return false;
    
    Vec2 ballCenter = ball.GetCenter();
    Rect ballRect = ball.GetRect();
    
    Vec2 rightBottom = Vec2(rect.pos.x + rect.width-1, rect.pos.y + rect.height-1);
    
    //bottom / top
    if((rect.IsCollideRect(ballRect)) && (ballCenter.x >= rect.pos.x) && (ballCenter.x <= rightBottom.x)){
        isDestroyed = true;
        ball.BounceY();
        return true;
    }
    
    //left / right
    if((rect.IsCollideRect(ballRect)) && (ballCenter.y >= rect.pos.y) && (ballCenter.y <= rightBottom.y)){
        isDestroyed = true;
        ball.BounceX();
        return true;
    }
   
    return false;
    
}

bool Brick::BallCollisionCorners(Ball &ball){
    if(isDestroyed)
        return false;
    
    Vec2 ballCenter = ball.GetCenter();
    Vec2 ballVel = ball.GetVelocity();
    int ballRadius = ball.GetRadius();
    
    Vec2 rightBottom = Vec2(rect.pos.x + rect.width-1, rect.pos.y + rect.height-1);
    Vec2 rightTop = Vec2(rect.pos.x + rect.width-1, rect.pos.y);
    Vec2 leftBottom = Vec2(rect.pos.x, rect.pos.y + rect.height-1);
    Vec2 leftTop = Vec2(rect.pos.x, rect.pos.y);
    
    //right bottom
    Vec2 rbDist = rightBottom - ballCenter;
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
    Vec2 rtDist = rightTop - ballCenter;
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
    Vec2 lbDist = leftBottom - ballCenter;
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
    Vec2 ltDist = leftTop - ballCenter;
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
