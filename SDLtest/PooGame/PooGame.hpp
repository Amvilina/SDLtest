#pragma once
#include "Game.hpp"
#include "Dude.hpp"
#include "Poo.hpp"

class PooGame : public Game {
public:
    PooGame();
private:
    
    void UpdateModel() override;
    void ComposeFrame() override;
    
    Dude dude;
    static const int NUMBER_OF_POOS =5;
    Poo poos[NUMBER_OF_POOS];

    Rect startRect;
    bool isStart;
    bool isEnd;
};
