#include "Snake.hpp"
namespace SnakeGame{

Point Snake::SnakeSegment::NextLocation(Direction dir) const{
    Point temp = loc;
    if(dir == Direction::UP)
        temp.Add({0,-1});
    if(dir == Direction::DOWN)
        temp.Add({0,1});
    if(dir == Direction::LEFT)
        temp.Add({-1,0});
    if(dir == Direction::RIGHT)
        temp.Add({1,0});
    
    return temp;
}

Snake::Snake() : nSegments(1){
    Color c[4]={
        {15,120,10},
        {15,150,10},
        {15,180,10},
        {15,210,10}
    };

    segments[0].color = headColor;
    
    
    for (int i = 1; i<MAX_SEGMENTS_NUMBER;++i)
        segments[i].color = c[i%4];
    
    Restart();
}

void Snake::Restart(){
    direction = Direction::RIGHT;
    nSegments = 1;
    segments[0].loc = {3,3};
}

void Snake::Draw(Board &brd) const{
    for (int i = 0; i<nSegments; ++i) {
        brd.DrawCell(segments[i].loc, segments[i].color);
    }
}

void Snake::Move(){
    for (int i = nSegments-1; i>0; --i)
        if(segments[i].loc == segments[i-1].loc)
            continue;
        else
            segments[i].loc = segments[i-1].loc;
    
    segments[0].loc = segments[0].NextLocation(direction);
}

bool Snake::CollideBorder() const{
    
    Point temp = segments[0].NextLocation(direction);
    
    return temp.x<0 || temp.y<0 || temp.x >= Board::GetWidth() || temp.y >= Board::GetHeight();
}

bool Snake::CollideTale() const{
    Point temp = segments[0].NextLocation(direction);
    
    for (int i = 0; i<nSegments-1; ++i) 
        if(temp == segments[i].loc)
            return true;
    
    
    return false;
}



void Snake::Grow(){
    segments[nSegments].loc = segments[nSegments-1].loc;
    ++nSegments;
}

Point Snake::NextHeadLocation() const{
    return segments[0].NextLocation(direction);
    
}

bool Snake::CollideSnake(const Point& pos) const{
    for (int i = 0; i<nSegments; ++i)
        if(segments[i].loc == pos)
            return true;
    
    return false;
}


void Snake::ChangeDirection(Direction dir){
    direction = dir;
}

Snake::Direction Snake::GetDirection() const{
    return direction;
}


}
