#include "Keyboard.hpp"

Keyboard::Keyboard() : lastReleased(0){
    for (int i = 0; i<NUMBER_OF_KEYS; ++i) {
        keys[i] = status::None;
    }
}

void Keyboard::Update(const SDL_Event &event){
   
    int key = event.key.keysym.sym;
    
   //special keys
    if (event.key.keysym.sym > 255)
        return;
    
        

    if (lastReleased) {
        keys[lastReleased] = status::None;
        lastReleased = 0;
    }
    
    
    if (event.type == SDL_KEYDOWN) {
        keys[key] = status::Pressed;
        return;
    }
            
    if (event.type == SDL_KEYUP) {
        keys[key] = status::Released;
        lastReleased = key;
        return;
    }
    
}

bool Keyboard::IsPressed(char scanCode) const{
    return keys[scanCode] == status::Pressed;
    
}

bool Keyboard::IsReleased(char scanCode) const{
    return keys[scanCode] == status::Released;
}
