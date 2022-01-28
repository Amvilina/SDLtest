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
    
    if (wnd.kbd.IsPressed(event, SDLK_w)) {
        w = true;
    }
    if (wnd.kbd.IsReleased(event, SDLK_w)) {
        w = false;
    }
    
    if (wnd.kbd.IsPressed(event, SDLK_s)) {
        s = true;
    }
    if (wnd.kbd.IsReleased(event, SDLK_s)) {
        s = false;
    }
    
    if (wnd.kbd.IsPressed(event, SDLK_a)) {
        a = true;
    }
    if (wnd.kbd.IsReleased(event, SDLK_a)) {
        a = false;
    }
    
    if (wnd.kbd.IsPressed(event, SDLK_d)) {
        d = true;
    }
    if (wnd.kbd.IsReleased(event, SDLK_d)) {
        d = false;
    }
    
    if (wnd.kbd.IsPressed(event, SDLK_SPACE)) {
        sp = true;
    }
    if (wnd.kbd.IsReleased(event, SDLK_SPACE)) {
        sp = false;
    }
    
    if (w) y = 200;
    if (s) y = 400;
    if (a) x = 300;
    if (d) x = 500;
    
    if (sp) {
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


