#pragma once
#include "Game.hpp"
#include "Board.hpp"
#include "Snake.hpp"

namespace SnakeGame{



class SnakeGame : public Game{
    
public:
    SnakeGame();
private:
    
    void UpdateModel() override;
    void ComposeFrame() override;

    Board brd;
    Snake snake;
    
    double snakeSecondsPerMove = 0.1;
    double snakeMinSecondsPerMove = 0.005;
    double snakeSecondsCounter = 0;
    double poisonSpeedBoost = 0.001;
    
    bool isDead = false;
    
    
    static constexpr int obstaclesMaxNumber = 20;
    int nObstacles = 3;
    
    static constexpr int nApples = 10;
    static constexpr int nPoisonStart = 100;
    
    Snake::Direction tempDirection = Snake::Direction::RIGHT;

};
    
    
    
    
}






