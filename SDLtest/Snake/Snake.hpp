#pragma once
#include "Game.hpp"
#include "Board.hpp"

namespace Snake{



class Snake : public Game{
    
public:
    Snake();
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
};
    
    
    
    
}






