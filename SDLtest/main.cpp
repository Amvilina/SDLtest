#include "PooGame.hpp"
#include "SnakeGame.hpp"
#include "Arcanoid.hpp"
#include "MineSweeper.hpp"

int main(int argc, const char * argv[]) {
    
    //SnakeGame::SnakeGame game;
    //PooGame::PooGame game;
    //Game game;
    //Arcanoid game;
    MineSweeper game;
    while(game.Go());
    

    return 0;
}

//TODO:
//II snake
