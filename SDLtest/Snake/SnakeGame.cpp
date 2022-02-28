#include "SnakeGame.hpp"
namespace SnakeGame{

SnakeGame::SnakeGame()
:
brd(gfx)
{
    snake.Restart();
    tempDirection = Snake::Direction::RIGHT;
    
    brd.Restart();
    
    for (int i = 0; i<nPoisonStart; ++i) {
        brd.Spawn(Board::TileType::Poison, snake);
    }
    
    for (int i = 0; i<nApples; ++i) {
        brd.Spawn(Board::TileType::Apple, snake);
    }
    
    for (int i = 0; i<nObstacles; ++i) {
        brd.Spawn(Board::TileType::Obstacle, snake);
    }
    

}

void SnakeGame::UpdateModel(){
    if(isDead)
        return;
    
    double dt = timer.Mark();
    
    if(wnd.kbd.IsPushed('w'))
        tempDirection = Snake::Direction::UP;
    if(wnd.kbd.IsPushed('s'))
        tempDirection = Snake::Direction::DOWN;
    if(wnd.kbd.IsPushed('a'))
        tempDirection = Snake::Direction::LEFT;
    if(wnd.kbd.IsPushed('d'))
        tempDirection = Snake::Direction::RIGHT;
    
    snakeSecondsCounter += dt;
    if (snakeSecondsCounter >= snakeSecondsPerMove) {
        
        snakeSecondsCounter -= snakeSecondsPerMove;
        
        switch (tempDirection) {
            case Snake::Direction::UP:
                if(snake.GetDirection() != Snake::Direction::DOWN)
                    snake.ChangeDirection(tempDirection);
                break;
            case Snake::Direction::DOWN:
                if(snake.GetDirection() != Snake::Direction::UP)
                    snake.ChangeDirection(tempDirection);
                break;
            case Snake::Direction::LEFT:
                if(snake.GetDirection() != Snake::Direction::RIGHT)
                    snake.ChangeDirection(tempDirection);
                break;
            case Snake::Direction::RIGHT:
                if(snake.GetDirection() != Snake::Direction::LEFT)
                    snake.ChangeDirection(tempDirection);
                break;
                
                
        }
        
        if(snake.CollideBorder() || snake.CollideTale()){
            isDead = true;
            return;
        }
        
        
        if(brd.GetType ( snake.NextHeadLocation() ) == Board::TileType::Obstacle) {
            isDead = true;
            return;
        }
        
        if(brd.GetType ( snake.NextHeadLocation() ) == Board::TileType::Poison){
            snakeSecondsPerMove = std::max(snakeMinSecondsPerMove, snakeSecondsPerMove-poisonSpeedBoost);
            brd.DeleteTile(snake.NextHeadLocation());
            return;
        }
        
        if (brd.GetType ( snake.NextHeadLocation() ) == Board::TileType::Apple) {
            
            brd.DeleteTile(snake.NextHeadLocation());
            
            snake.Grow();
            snake.Move();
           
            if(nObstacles < obstaclesMaxNumber){
                brd.Spawn(Board::TileType::Obstacle, snake);
                ++nObstacles;
            }
            brd.Spawn(Board::TileType::Apple, snake);
            
        }else{
            snake.Move();
        }
        
        
        
    }
    
    
}

void SnakeGame::ComposeFrame(){
    brd.DrawBoard();
    brd.DrawBorder();
    snake.Draw(brd);
}


}
