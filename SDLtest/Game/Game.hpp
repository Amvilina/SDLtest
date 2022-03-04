#pragma once
#include <iostream>
#include <SDL.h>
#include "Graphics.hpp"
#include "MainWindow.hpp"
#include "Rect_.hpp"
#include "Random.hpp"
#include "Timer.hpp"

#include "Animation.hpp"
#include "Character.hpp"
#include "Font.hpp"


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
    
    
    Character ch = Character("images/link90x90.bmp", {100,100}, 90, 90, 80, 4, Colors::Magenta);
    Character ch2 = Character("images/link90x90.bmp", {100,100}, 90, 90, 80, 4, Colors::Magenta);
    Font font1 = Font("fonts/16x28.bmp", Colors::White);
    Font font2 = Font("fonts/13x24.bmp", Colors::White);
};
