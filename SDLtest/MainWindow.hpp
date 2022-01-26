#pragma once
#include <SDL.h>
#include <iostream>
#include "Keyboard.hpp"

class MainWindow{
public:
    MainWindow();
    bool Initialize(const char* title, int xpos, int ypos, int width, int height);
    ~MainWindow();
    
    SDL_Window* GetSDLWindow() const;
    int GetWidth() const;
    int GetHeight() const;
    
    Keyboard kbd;
    
private:
    bool isInit;
    SDL_Window* window;
    
};
