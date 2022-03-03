#pragma once
#include "Graphics.hpp"
#include <vector>

class Animation{
public:
    Animation(const Surface& srf, int x, int y, int width, int height, int count, double holdTime, Color chroma);
public:
    void Draw(const iVec2& pos, Graphics& gfx) const;
    void Draw(const iVec2& pos, Graphics& gfx, const Rect& clipRect) const;
    void DrawSubstitute(const iVec2& pos, Graphics& gfx, const Color& substituteColor) const;
    void DrawSubstitute(const iVec2& pos, Graphics& gfx, const Rect& clipRect, const Color& substituteColor) const;
    void Update(double dt);
private:
    const Surface& surface;
    const Color chromoColor;
    
    std::vector<Rect> frames;
    int iCurFrame = 0;
    
    const double holdTime;
    double curTime = 0.0;
};
