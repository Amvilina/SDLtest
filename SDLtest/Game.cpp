#include "Game.hpp"



Game::Game() : posx(100), posy(100){
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout<<"Subsystem initialized!\n";
        
        if (wnd.Initialize("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400)) {
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
        HandleEvents();
        UpdateModel();
        ComposeFrame();
    }
}

void Game::HandleEvents(){
    SDL_Event event;
    
    SDL_PollEvent(&event);
    
    if (wnd.kbd.IsPressed(event, SDLK_w))
        pressed = true;
    
    if(wnd.kbd.IsReleased(event, SDLK_w))
        pressed = false;

    if (pressed) {
        posx ++;
        posy +=2;
    }
    
    if(wnd.kbd.IsReleased(event, SDLK_r) || wnd.mouse.LeftIsPressed()){
        
        posx = wnd.mouse.GetPosX();
        posy = wnd.mouse.GetPosY();
    }
    
    
    if (event.type == SDL_QUIT) {
        isRunning = false;
    }
    
    
    
}

void Game::UpdateModel(){
    
}

void Game::ComposeFrame(){
    gfx.StartFrame();
 
    
    
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


