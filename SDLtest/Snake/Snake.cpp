#include "Snake.hpp"
namespace SnakeGame{

Snake::Snake() : nSegments(1){
    Color c[4]={
        {15,120,10},
        {15,150,10},
        {15,180,10},
        {15,210,10}
    };

    segments[0].color = headColor;
    segments[0].loc = {3,3};
    
    for (int i = 1; i<MAX_SEGMENTS_NUMBER;++i)
        segments[i].color = c[i%4];
    
    Restart();
}

void Snake::Restart(){
    direction = Direction::RIGHT;
    nSegments = 1;
}

void Snake::Draw(Board &brd) const{
    for (int i = 0; i<nSegments; ++i) {
        brd.DrawCell(segments[i].loc.x, segments[i].loc.y, segments[i].color);
    }
}

void Snake::Move(){
    for (int i = nSegments-1; i>0; --i)
        if(segments[i].loc == segments[i-1].loc)
            continue;
        else
            segments[i].loc = segments[i-1].loc;
    
    if(direction == Direction::UP)
        segments[0].loc.Add({0,-1});
    if(direction == Direction::DOWN)
        segments[0].loc.Add({0,1});
    if(direction == Direction::LEFT)
        segments[0].loc.Add({-1,0});
    if(direction == Direction::RIGHT)
        segments[0].loc.Add({1,0});
}

void Snake::Grow(){
    segments[nSegments].loc = segments[nSegments-1].loc;
    ++nSegments;
}

void Snake::ChangeDirection(Direction dir){
    direction = dir;
}

Snake::Direction Snake::GetDirection() const{
    return direction;
}


}
