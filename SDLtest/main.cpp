#include "Game.hpp"
#include "PooGame.hpp"
#include "SnakeGame.hpp"
#include "Arcanoid.hpp"
#include "MineSweeper.hpp"

int main(int argc, const char * argv[]) {
    
    Game game;
    //PooGame::PooGame game;
    //SnakeGame::SnakeGame game;
    //Arcanoid game;
    //MineSweeper game;
    while(game.Go());

    return 0;
}

