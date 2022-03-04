#pragma once
#include <cmath>
#include <cassert>

template <class T>
class Vec2_{
public:
    T x;
    T y;
public:
    constexpr Vec2_() : x( T(0) ) , y( T(0) ) {};
    constexpr Vec2_(T x, T y) : x( x ) , y( y ) {};
    constexpr Vec2_(const Vec2_& other) : x( other.x ) , y( other.y ) {};
    Vec2_& operator=(const Vec2_& other){x = other.x; y = other.y; return *this;}
public:
    template <class S>
    explicit operator Vec2_<S>() const
    {
        return Vec2_<S>{S(x), S(y)};
    }
public:
    Vec2_& operator+=(const Vec2_& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    constexpr Vec2_  operator+(const Vec2_& other) const
    {
        Vec2_ result = *this;
        result += other;
        return result;
    }
    
    Vec2_& operator-=(const Vec2_& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    constexpr Vec2_  operator-(const Vec2_& other) const
    {
        Vec2_ result = *this;
        result -= other;
        return result;
    }
    
    Vec2_& operator*=(T k)
    {
        x *= k;
        y *= k;
        return *this;
    }
    constexpr Vec2_  operator*(T k) const
    {
        Vec2_ result = *this;
        result *= k;
        return result;
    }
    
    Vec2_& operator/=(T k)
    {
        assert( k != T(0) );
        x /= k;
        y /= k;
        return *this;
    }
    constexpr Vec2_  operator/(T k) const
    {
        Vec2_ result = *this;
        result /= k;
        return result;
    }
public:
    bool operator==(const Vec2_& other) const{return x == other.x && y == other.y;}
    bool operator!=(const Vec2_& other) const{return !(*this == other);}
public:
    constexpr T GetLengthSq() const
    {
        return T(x * x + y * y);
    }
    constexpr T GetLength() const
    {
        return T(std::sqrt(GetLengthSq()));
    }
    Vec2_& Normalize()
    {
        if(GetLength() == T(0))
            return *this;
        *this /= GetLength();
        return *this;
    }
    constexpr Vec2_ GetNormalized() const
    {
        Vec2_ Result = *this;
        Result.Normalize();
        return Result;
    }
private:
    bool IsEqual(T a, T b) const
    {
        T diff = std::abs(a - b);
        if (diff <= T(10e-12))
            return true;
        return diff <= ((std::abs(a) < std::abs(b) ? std::abs(b) : std::abs(a)) * T(10e-9) );
    }
};

using Vec2 = Vec2_<double>;
using Vei2 = Vec2_<int>;


