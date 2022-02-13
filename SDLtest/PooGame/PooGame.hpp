#pragma once
#include "Game.hpp"
#include "Dude.hpp"
#include "Poo.hpp"
#include "Goal.hpp"

namespace PooGame{
class PooGame : public Game {
public:
    PooGame();
private:
    
    
    void Restart() override;
    
    void UpdateModel() override;
    void ComposeFrame() override;
    bool PooCollision() const;
    bool GoalCollision() const;
    
    void DrawScore();
    
    Dude dude;
    static const int NUMBER_OF_POOS = 10;
    Poo poos[NUMBER_OF_POOS];

    Goal goal;
    int score;

};

}
