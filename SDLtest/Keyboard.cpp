#include "Keyboard.hpp"

Keyboard::Keyboard() : lastReleased(0){
    for (int i = 0; i<NUMBER_OF_KEYS; ++i) {
        keys[i] = status::None;
    }
}

void Keyboard::Update(const SDL_Event &event){
   
    if (event.key.keysym.sym > 255) 
        return;
    
    if (lastReleased) {
        keys[lastReleased] = status::None;
        lastReleased = 0;
    }
    
    
    if (event.type == SDL_KEYDOWN) {
        keys[event.key.keysym.sym] = status::Pressed;
        return;
    }
            
    if (event.type == SDL_KEYUP) {
        keys[event.key.keysym.sym] = status::Released;
        lastReleased = event.key.keysym.sym;
        return;
    }
    
}

bool Keyboard::IsPressed(char scanCode) const{
    return keys[scanCode] == status::Pressed;
    
}

bool Keyboard::IsReleased(char scanCode) const{
    return keys[scanCode] == status::Released;
}
