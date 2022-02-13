#pragma once
#include "dVec2.hpp"
class dVec2;

class iVec2{
public:
    int x;
    int y;

    constexpr iVec2():x(0),y(0){}
    constexpr iVec2(int x, int y):x(x),y(y){}
    constexpr iVec2(const iVec2& other):x(other.x),y(other.y){}

    iVec2  operator+(const iVec2& other) const;
    iVec2  operator-(const iVec2& other) const;
    iVec2  operator*(int k) const;
    iVec2& operator=(const iVec2& other);
    iVec2& operator+=(const iVec2& other);
    iVec2& operator-=(const iVec2& other);
    iVec2& operator*=(int k);
    bool operator==(const iVec2& other) const;
    bool operator!=(const iVec2& other) const;

    int GetLengthSq() const;
    double GetLength() const;

    operator dVec2() const;
};
