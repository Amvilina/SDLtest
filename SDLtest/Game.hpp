#pragma once
#include <iostream>
#include <SDL.h>
#include "Graphics.hpp"
#include "MainWindow.hpp"


class Game {
public:
    Game();
    ~Game();
    
    void Go();
    void UpdateModel();
    void ComposeFrame();
    
    
    
private:
    bool isRunning;
    MainWindow wnd;
    Graphics gfx;
   
};
