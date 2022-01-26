#include "Keyboard.hpp"

bool Keyboard::IsPressed(const SDL_Event& event, int scanCode){
    if (event.type == SDL_KEYDOWN)
        if(event.key.keysym.sym == scanCode)
            return true;
    
    return false;
    
}

bool Keyboard::IsReleased(const SDL_Event& event, int scanCode){
    if(event.type == SDL_KEYUP)
        if (event.key.keysym.sym == scanCode)
            return true;
        
    return false;
}
