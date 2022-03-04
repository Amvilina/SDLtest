#pragma once
#include <SDL.h>
#include "Rect_.hpp"


class Mouse{
public:
    int GetPosX() const;
    int GetPosY() const;
    Vei2 GetPos() const;
    RectI GetRect() const;
public:
    bool LeftIsPressed() const;
    bool RightIsPressed() const;
    
};
