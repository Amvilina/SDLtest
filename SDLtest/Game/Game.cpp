#include "Game.hpp"



Game::Game():gfx(wnd) {
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
    
    UpdateModel();
    ComposeFrame();
    
    
    gfx.EndFrame();
    
    return isRunning;
}


  
    


