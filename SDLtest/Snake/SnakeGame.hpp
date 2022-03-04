#pragma once
#include "Game.hpp"
#include "Board.hpp"
#include "Snake.hpp"
#include <string>

namespace SnakeGame{



class SnakeGame : public Game{
    
public:
    SnakeGame();
private:
    
    void UpdateModel() override;
    void ComposeFrame() override;

    void LoadSettings(const std::string& name);
    
    const std::string settingsFileName {"SnakeGame/Settings.txt"};
    
    double snakeSecondsPerMove = 1;
    static constexpr double snakeMinSecondsPerMove = 0.005;
    double snakeSecondsCounter = 0;
    double poisonSpeedBoost;
    
    bool isDead = false;
    bool isPlaying = false;
    
    int dimension;
    int width;
    int height;
    
    int obstaclesMaxNumber;
    int nObstacles = 3;
    
    int nApples;
    int nPoisonStart;
    
    Board brd;
    Snake snake;
    
    Snake::Direction tempDirection = Snake::Direction::RIGHT;

};
    
    
    
    
}






