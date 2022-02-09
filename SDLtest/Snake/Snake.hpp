#pragma once
#include "Board.hpp"
namespace SnakeGame{

class Snake{
public:
    enum class Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    
private:
    
    class SnakeSegment{
    public:
        iVec2 NextLocation(Direction dir) const;
        iVec2 loc;
        Color color;
    };
    
public:
    Snake();
    void Restart();
    void Draw(Board& brd) const;
    void Move();
    bool CollideBorder() const;
    bool CollideTale() const;
    void Grow();
    iVec2 NextHeadLocation() const;
    bool CollideSnake(const iVec2& pos) const;
    
    void ChangeDirection(Direction dir);
    Direction GetDirection() const;
    
private:
    int nSegments;
    static constexpr int MAX_SEGMENTS_NUMBER = Board::GetWidth() * Board::GetHeight();
    SnakeSegment segments[MAX_SEGMENTS_NUMBER];
    
    static constexpr Color headColor = Colors::Yellow;
    
    Direction direction;
};


}
