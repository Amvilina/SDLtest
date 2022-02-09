#pragma once
#include "dVec2.hpp"
class dVec2;

class iVec2{
public:
    int x;
    int y;

    iVec2();
    iVec2(int x, int y);
    iVec2(const iVec2& other);

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
