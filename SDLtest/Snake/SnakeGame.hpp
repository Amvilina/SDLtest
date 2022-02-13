#pragma once
#include "Game.hpp"
#include "Board.hpp"
#include "Snake.hpp"
#include "Apple.hpp"
#include "Obstacle.hpp"

namespace SnakeGame{



class SnakeGame : public Game{
    
public:
    SnakeGame();
private:
    void Restart() override;
    
    void UpdateModel() override;
    void ComposeFrame() override;

    Board brd;
    Snake snake;
    Apple apple;
    
    double snakeSecondsPerMove;
    static constexpr double snakeMinSecondsPerMove = 0.03;
    double snakeSecondsCounter;
    
    int score;
    
    static constexpr int obstaclesMaxNumber = 20;
    Obstacle obstacles[obstaclesMaxNumber];
    int numberOfObstacles;
    
    Snake::Direction tempDirection = Snake::Direction::RIGHT;

};
    
    
    
    
}






