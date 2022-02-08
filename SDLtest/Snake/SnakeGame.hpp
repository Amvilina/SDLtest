#pragma once
#include "Game.hpp"
#include "Board.hpp"
#include "Snake.hpp"
#include "Apple.hpp"

namespace SnakeGame{



class SnakeGame : public Game{
    
public:
    SnakeGame();
private:
    void Restart();
    
    void UpdateModel() override;
    void ComposeFrame() override;

    Rect startRect;
    enum class GameState{
        MainMenu,
        Game,
        Pause,
        End
    };
    GameState gameState;

    
    Board brd;
    Snake snake;
    Apple apple;
    
    static constexpr int SNAKE_FRAMES_PER_MOVE = 10;
    int snakeFrameCounter;
    
    Snake::Direction tempDirection = Snake::Direction::RIGHT;

};
    
    
    
    
}






