#include "PooGame.hpp"
#include "SnakeGame.hpp"

int main(int argc, const char * argv[]) {
    
    //SnakeGame::SnakeGame game;
    PooGame::PooGame game;
    while(game.Go());
    

    return 0;
}

//TODO:
//class for randomizer
//speed up snake due to time
//add obstacles to snake
//II snake
