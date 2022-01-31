#pragma once
#include <SDL.h>
#include <iostream>

class Keyboard{
public:
    Keyboard();
    bool IsPressed (char symbol) const;
    bool IsReleased(char symbol) const;
    void Update(const SDL_Event& event);
    
private:
    enum class status{
        None,
        Pressed,
        Released
    };
    static constexpr int NUMBER_OF_KEYS = 256;
    status keys[NUMBER_OF_KEYS];
};



