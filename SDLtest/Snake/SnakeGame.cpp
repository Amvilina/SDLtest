#include "SnakeGame.hpp"
namespace SnakeGame{

SnakeGame::SnakeGame()
:
brd(gfx),
snakeSecondsCounter(0)
{}


void SnakeGame::Restart(){
    snake.Restart();
    tempDirection = Snake::Direction::RIGHT;
    do {
        apple.Spawn();
    } while (snake.CollideSnake(apple.GetPosition()));
    
    score = 0;
    snakeSecondsPerMove = 0.09;
    snakeSecondsCounter = 0;
    
    numberOfObstacles = 0;
}


void SnakeGame::UpdateModel(){
    
    double dt = timer.Mark();
    if(wnd.kbd.IsReleased(' '))
        gameState = GameState::Pause;
    
    
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
            gameState = GameState::End;
            return;
        }
        
        
        for (int i = 0; i<numberOfObstacles; ++i)
            if(obstacles[i].GetPosition() == snake.NextHeadLocation()){
                gameState = GameState::End;
                return;
            }
        
        
        
        if (snake.NextHeadLocation() == apple.GetPosition()) {
            snake.Grow();
            snake.Move();
            
            bool flag = false;
            do {
                apple.Spawn();
                flag = false;
                flag = flag || snake.CollideSnake(apple.GetPosition());
                flag = flag || (apple.GetPosition() == snake.NextHeadLocation());
                for (int i=0; i<numberOfObstacles; ++i)
                    flag = flag || (obstacles[i].GetPosition()==apple.GetPosition());
                
            } while ( flag );
            
            if(numberOfObstacles >= obstaclesMaxNumber)
            {
            }else{
                do {
                    obstacles[numberOfObstacles].Spawn();
                    iVec2 obstPos = obstacles[numberOfObstacles].GetPosition();
                    flag = false;
                    flag = flag || snake.CollideSnake(obstPos);
                    flag = flag || (obstPos == snake.NextHeadLocation());
                    flag = flag || (obstPos == apple.GetPosition());
                    for (int i=0; i<numberOfObstacles; ++i)
                        flag = flag || (obstacles[i].GetPosition()==obstPos);
                } while (flag);
                
                ++numberOfObstacles;
            }
            
            ++score;
            if(score%5 ==0)
                snakeSecondsPerMove = std::max(snakeSecondsPerMove-0.02, snakeMinSecondsPerMove);
            
        }else{
            snake.Move();
        }
        
        
        
    }
    
    
}
void SnakeGame::ComposeFrame(){
    brd.DrawBoard();
    brd.DrawBorder();
    snake.Draw(brd);
    apple.Draw(brd);
    for (int i = 0; i<numberOfObstacles; ++i)
        obstacles[i].Draw(brd);
    
}


}
