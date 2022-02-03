#pragma once
#include <SDL.h>
#include "Vec2.hpp"

class Mouse{
public:
    int GetPosX() const;
    int GetPosY() const;
    Vec2 GetPos() const;
    
    bool LeftIsPressed() const;
    bool RightIsPressed() const;
    
};
