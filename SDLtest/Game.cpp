#include "Game.hpp"



Game::Game() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout<<"Subsystem initialized!\n";
        
        if (wnd.Initialize("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600)) {
            std::cout<<"Window created!\n";
        }
        
        if (gfx.Initialize(wnd.GetSDLWindow())) {
            std::cout<<"Renderer created!\n";
        }
        
        isRunning = true;
        Go();
    }else{
        isRunning = false;
    }
}


Game::~Game(){
    SDL_Quit();
    std::cout<<"Ending...\n";
}


void Game::Go(){
    while (isRunning) {
        UpdateModel();
        ComposeFrame();
    }
}

void Game::UpdateModel(){
    
}

void Game::ComposeFrame(){
    
    SDL_Event event;
    SDL_PollEvent(&event);
    
    if (event.type == SDL_QUIT) {
        isRunning = false;
    }
    
    
    gfx.StartFrame();
 
    int x = 400,y = 300;
    wnd.kbd.Update(event);
    if (wnd.kbd.IsPressed('w')) {
        y = 200;
    }
    
    
    if (wnd.kbd.IsPressed('s')) {
        y = 400;
    }
    
    
    if (wnd.kbd.IsPressed('a')) {
        x = 300;
    }
    
    
    if (wnd.kbd.IsPressed('d')) {
        
        x = 500;
    }
    
    
   

    if (wnd.kbd.IsPressed(' ')) {
        gfx.PutPixel(x+1, y, 255, 255, 255);
        gfx.PutPixel(x+2, y);
        gfx.PutPixel(x+3, y);
        gfx.PutPixel(x+4, y);
        
        gfx.PutPixel(x-1, y);
        gfx.PutPixel(x-2, y);
        gfx.PutPixel(x-3, y);
        gfx.PutPixel(x-4, y);
        
        gfx.PutPixel(x, y+1);
        gfx.PutPixel(x, y+2);
        gfx.PutPixel(x, y+3);
        gfx.PutPixel(x, y+4);
        
        gfx.PutPixel(x, y-1);
        gfx.PutPixel(x, y-2);
        gfx.PutPixel(x, y-3);
        gfx.PutPixel(x, y-4);
        
    }else{
        gfx.PutPixel(x+1, y, 0, 255, 255);
        gfx.PutPixel(x+2, y);
        gfx.PutPixel(x+3, y);
        gfx.PutPixel(x+4, y);
        
        gfx.PutPixel(x-1, y);
        gfx.PutPixel(x-2, y);
        gfx.PutPixel(x-3, y);
        gfx.PutPixel(x-4, y);
        
        gfx.PutPixel(x, y+1);
        gfx.PutPixel(x, y+2);
        gfx.PutPixel(x, y+3);
        gfx.PutPixel(x, y+4);
        
        gfx.PutPixel(x, y-1);
        gfx.PutPixel(x, y-2);
        gfx.PutPixel(x, y-3);
        gfx.PutPixel(x, y-4);
    }
    
    
  
  
    
    
    
    gfx.EndFrame();
}


