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
    static const int NUMBER_OF_POOS =50;
    Poo poos[NUMBER_OF_POOS];

    bool isStart;
};
