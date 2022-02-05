#pragma once
#include "Game.hpp"
#include "Dude.hpp"
#include "Poo.hpp"
namespace PooGame{
class PooGame : public Game {
public:
    PooGame();
private:
    void Restart();
    
    void UpdateModel() override;
    void ComposeFrame() override;
    bool PooCollision(const Dude& dude, const Poo& poo ) const;
    
    Dude dude;
    static const int NUMBER_OF_POOS =5;
    Poo poos[NUMBER_OF_POOS];

    Rect startRect;
    
    enum class GameState{
        MainMenu,
        Game,
        Pause,
        End
    };
    
    GameState gameState;

};
}
