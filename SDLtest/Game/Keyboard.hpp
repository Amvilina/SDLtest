#pragma once
#include <SDL.h>
#include <iostream>

class Keyboard{
public:
    Keyboard();
    
    bool IsPressed (char scanCode) const;
    bool IsPushed (char scanCode) const;
    bool IsReleased(char scanCode) const;
    
    void Update(const SDL_Event& event);
    
private:
    enum class status{
        None,
        Pushed,
        Pressed,
        Released
    };
    static constexpr int NUMBER_OF_KEYS = 256;
    status keys[NUMBER_OF_KEYS];
    
    char lastReleased;
    char lastPushed;
};



