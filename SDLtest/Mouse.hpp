#pragma once
#include <SDL.h>

class Mouse{
public:
    int GetPosX() const;
    int GetPosY() const;
    
    bool LeftIsPressed() const;
    bool RightIsPressed() const;
    
};
