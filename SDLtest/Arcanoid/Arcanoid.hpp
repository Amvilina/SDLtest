#pragma once
#include "Game.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"

class Arcanoid : public Game{
public:
    Arcanoid();
    void UpdateModel() override;
    void ComposeFrame() override;
    //void Restart() override;
    
private:
    Ball ball;
    Paddle paddle;
    
    static constexpr dVec2 topLeft = dVec2(50,100);
    static constexpr int horizontalNumber = 14;
    static constexpr int verticalNumber = 4;
    static constexpr int brickWidth = 50;
    static constexpr int brickHeight = 20;
    
    Brick bricks[horizontalNumber * verticalNumber];
    
};
