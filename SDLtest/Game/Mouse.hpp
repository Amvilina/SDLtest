#pragma once
#include <SDL.h>
#include "iVec2.hpp"

class Mouse{
public:
    int GetPosX() const;
    int GetPosY() const;
    iVec2 GetPos() const;
    
    bool LeftIsPressed() const;
    bool RightIsPressed() const;
    
};
