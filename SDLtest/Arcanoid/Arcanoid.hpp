#pragma once
#include "Game.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"

class Arcanoid : public Game{
public:
    //Arcanoid();
    void UpdateModel() override;
    void ComposeFrame() override;
    //void Restart() override;
    
private:
    Ball ball;
};
