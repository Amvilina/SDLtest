#pragma once
#include "Board.hpp"
namespace SnakeGame{

class Snake{
private:
    
    class SnakeSegment{
    public:
        Point loc;
        Color color;
    };
    
public:
    Snake();
    void Restart();
    void Draw(Board& brd) const;
    void Move();
    void Grow();
    
    enum class Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    
    void ChangeDirection(Direction dir);
    Direction GetDirection() const;
    
private:
    int nSegments;
    static constexpr int MAX_SEGMENTS_NUMBER = 100;
    SnakeSegment segments[MAX_SEGMENTS_NUMBER];
    
    Color headColor = {150,150,10};
    
    Direction direction;
};


}
