#include "Game.hpp"



Game::Game()
:
gfx(wnd),
gameState(GameState::MainMenu)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout<<"Subsystem initialized!\n";
        
        if (wnd.Initialize("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600)) {
            std::cout<<"Window created!\n";
        }
        
        if (gfx.Initialize()) {
            std::cout<<"Renderer created!\n";
        }
        
        isRunning = true;
        
    }else{
        isRunning = false;
    }
}


Game::~Game(){
    SDL_Quit();
    std::cout<<"Ending...\n";
}


bool Game::Go(){
    gfx.StartFrame();
    
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        isRunning = false;
    }
    wnd.kbd.Update(event);
    
    switch (gameState) {
        case GameState::MainMenu:
            MainMenu();
            DrawMainMenu();
            break;
        case GameState::Game:
            UpdateModel();
            ComposeFrame();
            if(wnd.kbd.IsReleased(' '))
                gameState = GameState::Pause;
            break;
        case GameState::Pause:
            Pause();
            DrawPause();
            break;
        case GameState::End:
            End();
            DrawEnd();
            break;
    }
    
    gfx.EndFrame();
    
    return isRunning;
}

//=================================================================================

void Game::MainMenu(){
    if((wnd.mouse.LeftIsPressed() && Rect(380, 290, 40, 20).IsCollideMouse(wnd)) || wnd.kbd.IsReleased(' ')){
        Restart();
        gameState = GameState::Game;
        timer.Reset();
    }
}
void Game::UpdateModel(){
    
}
void Game::Pause(){
    if(wnd.kbd.IsReleased(' ')){
        gameState = GameState::Game;
        timer.Reset();
    }
}
void Game::End(){
    if(wnd.kbd.IsReleased(' '))
        gameState = GameState::MainMenu;
}

//=================================================================================

void Game::DrawMainMenu(){
    gfx.DrawRectDim(380, 290, 40, 20, Colors::Green);
}
void Game::ComposeFrame(){

}
void Game::DrawPause(){
    ComposeFrame();
}
void Game::DrawEnd(){
    ComposeFrame();
}

//=================================================================================

void Game::Restart(){
    
}
