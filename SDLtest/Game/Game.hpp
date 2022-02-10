#pragma once
#include <iostream>
#include <SDL.h>
#include "Graphics.hpp"
#include "MainWindow.hpp"
#include "Rect.hpp"
#include "Random.hpp"
#include "Timer.hpp"


class Game {
public:
    Game();
    ~Game();
 
    bool Go();
    
protected:
    void virtual UpdateModel();
    void virtual ComposeFrame();
    
    bool isRunning;
    MainWindow wnd;
    Graphics gfx;
    Timer timer;
};
