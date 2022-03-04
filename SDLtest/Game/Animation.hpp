#pragma once
#include "Graphics.hpp"
#include <vector>

class Animation{
public:
    Animation(const Surface& srf, int x, int y, int width, int height, int count, double holdTime);
public:
    template <class SpecialEffect>
    void Draw(const Vei2& pos, Graphics& gfx, SpecialEffect effect) const
    {
        gfx.DrawSurface(pos.x, pos.y, surface, frames[iCurFrame], effect);
    }
    template <class SpecialEffect>
    void Draw(const Vei2& pos, Graphics& gfx, const Rect& clipRect, SpecialEffect effect) const
    {
        gfx.DrawSurface(pos.x, pos.y, surface, frames[iCurFrame], clipRect, effect);
    }
    void Update(double dt);
private:
    const Surface& surface;
    
    std::vector<RectI> frames;
    int iCurFrame = 0;
    
    const double holdTime;
    double curTime = 0.0;
};
