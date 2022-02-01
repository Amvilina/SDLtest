#include "Game.hpp"



Game::Game() :velx(0),vely(0), x(100), y(100), changeColor(false) {
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
    }
}

void Game::UpdateModel(){
    int max = 5;
    if (wnd.kbd.IsReleased('d')) {
        velx +=1;
    }
    if (wnd.kbd.IsReleased('a')) {
        velx -=1;
    }
    if (wnd.kbd.IsReleased('w')) {
        vely -=1;
    }
    if (wnd.kbd.IsReleased('s')) {
        vely +=1;
    }
    
    if (velx > max)
        velx = max;
    
    if (vely > max)
        vely = max;
    
    if (velx < -max)
        velx = -max;
    
    if (vely < -max)
        vely = -max;
   
    x += velx;
    y += vely;
    
    
    
    changeColor = wnd.kbd.IsPressed('a') || wnd.kbd.IsPressed('d') || wnd.kbd.IsPressed('s') || wnd.kbd.IsPressed('w');
    
    
    
}

void Game::ComposeFrame(){
    

    if (changeColor) {
        gfx.SetColor({255,255,255});
        gfx.PutPixel(x+1, y);
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
        gfx.SetColor({0,255,255});
        gfx.PutPixel(x+1, y);
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
    
    
  
  
    
    
    
    
}


