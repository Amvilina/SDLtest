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
    
private:
    Ball ball;
    Paddle paddle;
    
    static constexpr dVec2 topLeft = dVec2(40,40);
    static constexpr int horizontalNumber = 18;
    static constexpr int verticalNumber = 4;
    static constexpr int brickWidth = 40;
    static constexpr int brickHeight = 24;
    
    Brick bricks[horizontalNumber * verticalNumber];
    
    bool isDead = false;
};
