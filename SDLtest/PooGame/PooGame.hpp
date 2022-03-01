#pragma once
#include "Game.hpp"
#include "Dude.hpp"
#include "Poo.hpp"
#include "Goal.hpp"
#include "Surface.hpp"

namespace PooGame{
class PooGame : public Game {
public:
    PooGame();
private:
    void UpdateModel() override;
    void ComposeFrame() override;
    
    bool PooCollision() const;
    bool GoalCollision() const;
    
    void DrawScore();
private:
    Dude dude;
    
    static const int NUMBER_OF_POOS = 10;
    Poo poos[NUMBER_OF_POOS];

    bool isStart;
    bool isDead;
    
    Goal goal;
    int score;
    
    void Restart();
    
    Surface srfStart = Surface("surf/poo_images/dapoopoo.bmp");
    Surface srfEnd = Surface("surf/poo_images/game_over.bmp");
};

}
