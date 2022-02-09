#include "Mouse.hpp"

int Mouse::GetPosX() const{
    int x;
    SDL_GetMouseState(&x, 0);
    return x;
}

int Mouse::GetPosY() const{
    int y;
    SDL_GetMouseState(0, &y);
    return y;
}

iVec2 Mouse::GetPos() const{
    int x,y;
    SDL_GetMouseState(&x, &y);
    return iVec2(x,y);
}

bool Mouse::LeftIsPressed() const{
    return (SDL_GetMouseState(0, 0) == SDL_BUTTON_LEFT);
}

bool Mouse::RightIsPressed() const{
    return (SDL_GetMouseState(0, 0) == SDL_BUTTON_RIGHT);
}


