#pragma once
#include <iostream>
#include <SDL.h>
#include "Graphics.hpp"
#include "Keyboard.hpp"

class Game {
public:
    Game(const char* title, int xpos = SDL_WINDOWPOS_CENTERED, int ypos = SDL_WINDOWPOS_CENTERED, int width = 600, int height = 400);
    ~Game();
    
    void Loop();
    void HandleEvents();
    void Update();
    void Render();
    
    
private:
    bool isRunning;
    SDL_Window *window;
    Graphics gfx;
    Keyboard kbd;
    
    int posx, posy;
};
