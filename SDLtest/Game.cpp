#include "Game.hpp"


    


Game::Game(const char* title, int xpos, int ypos, int width, int height) : posx(100), posy(100){
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout<<"Subsystem initialized!\n";
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
        if (window) {
            std::cout<<"Window created!\n";
        }
        
        if (gfx.Initialize(window)) {
            std::cout<<"Renderer created!\n";
        }
        
        isRunning = true;
        Loop();
    }else{
        isRunning = false;
    }
}


Game::~Game(){
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout<<"Ending...\n";
}


void Game::Loop(){
    while (isRunning) {
        HandleEvents();
        Update();
        Render();
    }
}

void Game::HandleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    
    kbd.HadleEvent(event);
    if (kbd.isActiveSPACE()) {
        if (kbd.isPressedUP()) {
            posy--;
        }
        if (kbd.isPressedDOWN()) {
            posy++;
        }
        if (kbd.isPressedLEFT()) {
            posx--;
        }
        if (kbd.isPressedRIGHT()) {
            posx++;
        }
    }else{
        if (kbd.isActiveUP()) {
            posy--;
        }
        if (kbd.isActiveDOWN()) {
            posy++;
        }
        if (kbd.isActiveLEFT()) {
            posx--;
        }
        if (kbd.isActiveRIGHT()) {
            posx++;
        }
    }
    
    
    if (event.type == SDL_QUIT) {
        isRunning = false;
    }
    
    
    
}

void Game::Update(){
    
}

void Game::Render(){
    gfx.StartFrame();
    gfx.Test();
    gfx.PutPixel(0, 0, {100,200,200});
    for (int i = 0; i<300; ++i) {
        gfx.PutPixel(i, i);
    }
    
    
    gfx.PutPixel(posx+1, posy+1, {255,255,255});
    gfx.PutPixel(posx+2, posy+2, {255,255,255});
    gfx.PutPixel(posx+3, posy+3, {255,255,255});
    gfx.PutPixel(posx+4, posy+4, {255,255,255});
    
    gfx.PutPixel(posx+1, posy-1, {255,255,255});
    gfx.PutPixel(posx+2, posy-2, {255,255,255});
    gfx.PutPixel(posx+3, posy-3, {255,255,255});
    gfx.PutPixel(posx+4, posy-4, {255,255,255});
    
    gfx.PutPixel(posx-1, posy+1, {255,255,255});
    gfx.PutPixel(posx-2, posy+2, {255,255,255});
    gfx.PutPixel(posx-3, posy+3, {255,255,255});
    gfx.PutPixel(posx-4, posy+4, {255,255,255});
    
    gfx.PutPixel(posx-1, posy-1, {255,255,255});
    gfx.PutPixel(posx-2, posy-2, {255,255,255});
    gfx.PutPixel(posx-3, posy-3, {255,255,255});
    gfx.PutPixel(posx-4, posy-4, {255,255,255});
    
    
    
    gfx.EndFrame();
}


