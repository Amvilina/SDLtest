#include "Game.hpp"

Game::Game(const char* title, int xpos, int ypos, int width, int height){
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout<<"Subsystem initialized!\n";
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
        if (window) {
            std::cout<<"Window created!\n";
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
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
    SDL_DestroyRenderer(renderer);
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
   
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
    SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
    SDL_RenderDrawLine(renderer, 340, 240, 320, 200);
    
    SDL_SetRenderDrawColor(renderer, 205, 0, 155, 255);
    double dx, dy,cx,cy,r;
    cx = cy = 200;
    r = 70;
       dx = floor(sqrt((2.0 * r ) ));
       SDL_RenderDrawLine(renderer, cx-dx, cy+r, cx+dx, cy+r);
       SDL_RenderDrawLine(renderer, cx-dx, cy-r, cx+dx, cy-r);
       for (dy = 1; dy <= r; dy += 1.0) {
            dx = floor(sqrt((2.0 * r * dy) - (dy * dy)));
            SDL_RenderDrawPoint(renderer, cx+dx, cy+r-dy);
            SDL_RenderDrawPoint(renderer, cx+dx, cy-r+dy);
            SDL_RenderDrawPoint(renderer, cx-dx, cy+r-dy);
            SDL_RenderDrawPoint(renderer, cx-dx, cy-r+dy);
       }
    
    SDL_RenderPresent(renderer);
    
  
   
}


