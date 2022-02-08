#include "Point.hpp"
namespace SnakeGame{


bool Point::operator==(const Point &other) const{
    return x == other.x && y == other.y;
}

void Point::Add(const Point &other){
    x += other.x;
    y += other.y;
}


}
