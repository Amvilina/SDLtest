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
    
    void virtual MainMenu();
    void virtual UpdateModel();
    void virtual Pause();
    void virtual End();
    
    void virtual DrawMainMenu();
    void virtual ComposeFrame();
    void virtual DrawPause();
    void virtual DrawEnd();
    
    void virtual Restart();
    
    MainWindow wnd;
    Graphics gfx;
    
    Timer timer;
    
    enum class GameState{
        MainMenu,
        Game,
        Pause,
        End
    };
    GameState gameState;
    
private:
    bool isRunning;
};
