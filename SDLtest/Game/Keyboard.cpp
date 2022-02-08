#include "Keyboard.hpp"

Keyboard::Keyboard() : lastReleased(0),lastPushed(0){
    for (int i = 0; i<NUMBER_OF_KEYS; ++i) {
        keys[i] = status::None;
    }
}

void Keyboard::Update(const SDL_Event &event){
   
    int key = event.key.keysym.sym;
    
   //special keys
    if (key > 255)
        return;


    if (lastReleased) {
        keys[lastReleased] = status::None;
        lastReleased = 0;
    }
    
    if(lastPushed){
        keys[lastPushed] = status::Pressed;
        lastPushed = 0;
    }
    
    if (event.type == SDL_KEYDOWN && keys[key] == status::None) {
        
        keys[key] = status::Pushed;
        lastPushed = key;
        return;
        
    }
    
    
    if (event.type == SDL_KEYUP) {
        keys[key] = status::Released;
        lastReleased = key;
        return;
    }
    
    
    
    
    
}

bool Keyboard::IsPushed(char scanCode) const{
    return keys[scanCode] == status::Pushed;
}

bool Keyboard::IsPressed(char scanCode) const{
    return keys[scanCode] == status::Pressed;
    
}

bool Keyboard::IsReleased(char scanCode) const{
    return keys[scanCode] == status::Released;
}
