#include "Snake.hpp"
namespace Snake{

Snake::Snake()
:
startRect(350,250,100,100),
gameState(GameState::MainMenu),
brd(gfx)
{}


void Snake::Restart(){}


void Snake::UpdateModel(){
    
    switch (gameState) {
        case GameState::MainMenu:
            if(wnd.mouse.LeftIsPressed() && startRect.IsCollideMouse(wnd)){
                Restart();
                gameState = GameState::Game;
            }
            break;
            
        case GameState::Pause:
            if(wnd.kbd.IsReleased(' '))
                gameState = GameState::Game;
            break;
            
        case GameState::Game:
        
            
            break;
            
        case GameState::End:
            if(wnd.kbd.IsReleased(' '))
                gameState = GameState::MainMenu;
            
    }
    
}
void Snake::ComposeFrame(){

    switch (gameState) {
        case GameState::MainMenu:
            gfx.DrawRect(startRect, {0,200,100});
            break;
        case GameState::Pause:
        case GameState::Game:
        case GameState::End:
            brd.DrawBoard();
            brd.DrawBorder();
            break;
    }
}


}
