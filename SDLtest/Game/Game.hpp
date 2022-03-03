#pragma once
#include <iostream>
#include <SDL.h>
#include "Graphics.hpp"
#include "MainWindow.hpp"
#include "Rect.hpp"
#include "Random.hpp"
#include "Timer.hpp"

#include "Animation.hpp"
#include "Character.hpp"


class Game {
public:
    Game();
    ~Game();
 
    bool Go();
    
protected:
    
    void virtual UpdateModel();
    void virtual ComposeFrame();
    
    MainWindow wnd;
    Graphics gfx;
    
    Timer timer;
    
private:
    bool isRunning;
    
    
    Character ch = Character("surf/I12-images/link90x90.bmp", {100,100}, 90, 90, 80, 4, Colors::Magenta);
};
