#include "Animation.hpp"

Animation::Animation(const Surface& srf, int x, int y, int width, int height, int count, double holdTime, Color chroma)
:
surface(srf),
holdTime(holdTime),
chromoColor(chroma)
{
    for (int i = 0; i<count; ++i)
        frames.emplace_back(x + width*i, y, width, height);
}


void Animation::Draw(const iVec2 &pos, Graphics &gfx) const{
    gfx.DrawSurface(pos.x, pos.y, surface, frames[iCurFrame], chromoColor);
}

void Animation::Draw(const iVec2& pos, Graphics& gfx, const Rect& clipRect) const{
    gfx.DrawSurface(pos.x, pos.y, surface, frames[iCurFrame], clipRect, chromoColor);
}

void Animation::Update(double dt){
    curTime += dt;
    while(curTime >= holdTime){
        curTime -= holdTime;
        
        ++iCurFrame;
        if (iCurFrame == frames.size())
            iCurFrame = 0;
        
    }
                               
}
