#pragma once

class Vec2{
public:
    double x;
    double y;

    Vec2();
    Vec2(double ox, double oy);
    Vec2(const Vec2& other);

    Vec2  operator+(const Vec2& other) const;
    Vec2  operator-(const Vec2& other) const;
    Vec2  operator*(double k) const;
    Vec2  operator/(double k) const;
    Vec2& operator=(const Vec2& other);
    Vec2& operator+=(const Vec2& other);
    Vec2& operator-=(const Vec2& other);
    Vec2& operator*=(double k);
    Vec2& operator/=(double k);

    Vec2& Normalize();
    Vec2 GetNormalized() const;
    double GetLengthSq() const;
    double GetLength() const;

};

