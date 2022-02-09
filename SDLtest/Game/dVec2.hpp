#pragma once
#include "iVec2.hpp"
class iVec2;

class dVec2{
public:
    double x;
    double y;

    dVec2();
    dVec2(double x, double y);
    dVec2(const dVec2& other);

    dVec2  operator+(const dVec2& other) const;
    dVec2  operator-(const dVec2& other) const;
    dVec2  operator*(double k) const;
    dVec2  operator/(double k) const;
    dVec2& operator=(const dVec2& other);
    dVec2& operator+=(const dVec2& other);
    dVec2& operator-=(const dVec2& other);
    dVec2& operator*=(double k);
    dVec2& operator/=(double k);
    bool operator==(const dVec2& other) const;
    bool operator!=(const dVec2& other) const;

    dVec2& Normalize();
    dVec2 GetNormalized() const;
    double GetLengthSq() const;
    double GetLength() const;

    operator iVec2() const;
    
private:
    bool IsEqual(double a, double b) const;
};

