#include "Game.hpp"

Game::Game(const char* title, int xpos, int ypos, int width, int height){
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
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
            
        default:
            break;
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
    
    gfx.EndFrame();
}


