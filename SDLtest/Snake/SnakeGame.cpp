#include "SnakeGame.hpp"
namespace SnakeGame{

SnakeGame::SnakeGame()
:
startRect(350,250,100,100),
gameState(GameState::MainMenu),
brd(gfx),
snakeFrameCounter(0)
{}


void SnakeGame::Restart(){
    snake.Restart();
    tempDirection = Snake::Direction::RIGHT;
    do {
        apple.Spawn();
    } while (snake.CollideSnake(apple.GetPosition()));
    
    score = 0;
    snakeFramesPerMove = 10;
    snakeFrameCounter = 0;
    
    numberOfObstacles = 0;
}


void SnakeGame::UpdateModel(){
    
    switch (gameState) {
        case GameState::MainMenu:
            if((wnd.mouse.LeftIsPressed() && startRect.IsCollideMouse(wnd)) || wnd.kbd.IsReleased(' ')){
                Restart();
                gameState = GameState::Game;
            }
            break;
            
        case GameState::Pause:
            if(wnd.kbd.IsReleased(' '))
                gameState = GameState::Game;
            break;
            
        case GameState::Game:
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
            
            ++snakeFrameCounter;
            if (snakeFrameCounter >= snakeFramesPerMove) {
                
                snakeFrameCounter = 0;
                
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
                    break;
                }
                
                bool flag = false;
                for (int i = 0; i<numberOfObstacles; ++i)
                    if(obstacles[i].GetPosition() == snake.NextHeadLocation()){
                        gameState = GameState::End;
                        flag = true;
                        break;
                    }
                if(flag)
                    break;
                
                
                if (snake.NextHeadLocation() == apple.GetPosition()) {
                    snake.Grow();
                    snake.Move();
                    
                    
                    
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
                            //Obstacle obst = obstacles[numberOfObstacles];
                            flag = false;
                            flag = flag || snake.CollideSnake(obstacles[numberOfObstacles].GetPosition());
                            flag = flag || (obstacles[numberOfObstacles].GetPosition() == snake.NextHeadLocation());
                            for (int i=0; i<numberOfObstacles-1; ++i)
                                flag = flag || (obstacles[i].GetPosition()==obstacles[numberOfObstacles].GetPosition());
                        } while (flag);
                        
                        ++numberOfObstacles;
                    }
                    
                    
                    
                    
                    ++score;
                    if(score%5 ==0)
                        snakeFramesPerMove = std::max(snakeFramesPerMove-1, snakeMinFramesPerMove);
                    
                    
                    
                }else{
                    snake.Move();
                }
                
                
                
            }
            break;
            
        case GameState::End:
            if(wnd.kbd.IsReleased(' '))
                gameState = GameState::MainMenu;
            
    }
    
}
void SnakeGame::ComposeFrame(){

    switch (gameState) {
        case GameState::MainMenu:
            gfx.DrawRect(startRect, {0,200,100});
            break;
        case GameState::Pause:
        case GameState::Game:
        case GameState::End:
            
            brd.DrawBoard();
            brd.DrawBorder();
            snake.Draw(brd);
            apple.Draw(brd);
            for (int i = 0; i<numberOfObstacles; ++i)
                obstacles[i].Draw(brd);
            
            break;
    }
}


}
