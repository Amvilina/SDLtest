#include "PooGame.hpp"
#include "SnakeGame.hpp"

int main(int argc, const char * argv[]) {
    
    SnakeGame::SnakeGame game;
    while(game.Go());
    
    return 0;
}
