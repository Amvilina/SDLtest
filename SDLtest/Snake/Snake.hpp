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
        Vei2 NextLocation(Direction dir) const;
        Vei2 loc;
        Color color;
    };
    
public:
    Snake(const Board& brd);
    ~Snake();
    void Restart();
    void Draw(Board& brd) const;
    void Move();
    bool CollideBorder() const;
    bool CollideTale() const;
    void Grow();
    Vei2 NextHeadLocation() const;
    bool CollideSnake(const Vei2& pos) const;
    
    void ChangeDirection(Direction dir);
    Direction GetDirection() const;
    
private:
    const Board& brd;
    
    int nSegments;
    int MAX_SEGMENTS_NUMBER;
    SnakeSegment* segments;
    
    static constexpr Color headColor = Color(0xFFC611);
    
    Direction direction;
};


}
