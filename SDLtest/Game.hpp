#pragma once
#include <iostream>
#include <SDL.h>
#include "Graphics.hpp"
#include "MainWindow.hpp"


class Game {
public:
    Game();
    ~Game();
 
    bool Go();
    
protected:
    void virtual UpdateModel() = 0;
    void virtual ComposeFrame() = 0;
    
    bool isRunning;
    MainWindow wnd;
    Graphics gfx;

};
