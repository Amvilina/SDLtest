#pragma once
namespace SnakeGame{

class Point {
public:
    bool operator==(const Point& other) const;
    void Add(const Point& other);
    int x;
    int y;
};




}
