#include "Animation.hpp"

Animation::Animation(const Surface& srf, int x, int y, int width, int height, int count, double holdTime)
:
surface(srf),
holdTime(holdTime)
{
    for (int i = 0; i<count; ++i)
        frames.emplace_back( Vei2 { x + width*i , y } , width, height);
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
