#pragma once
#include "Vec2_.hpp"

template <class T>
class Rect_{
public:
    Vec2_<T> pos;
    T width;
    T height;
public:
    Rect_() : pos(Vec2_<T>()) , width( T(0) ) , height( T(0) ) {}
    Rect_(const Vec2_<T>& pos, T width, T height) : pos( pos ) , width( width ) , height( height )
    {
        assert( width >= 0 && height >= 0 );
    }
    Rect_(T left, T right, T top, T bottom) : pos( left, top ) , width( right - left) , height( bottom - top )
    {
        assert( right >= left && bottom >= top);
    }
public:
public:
    template <class S>
    explicit operator Rect_<S>() const
    {
        return Rect_<S>{ Vec2_<S>(pos) , S(width) , S(height) };
    }
public:
    enum class Collision{
        None        = 0b00000000,
        Left        = 0b00000001,
        Right       = 0b00000010,
        Top         = 0b00000100,
        Bottom      = 0b00001000,
        LeftTop     = 0b00000101,
        LeftBottom  = 0b00001001,
        RightTop    = 0b00000110,
        RightBottom = 0b00001010
    };
public:
    bool IsCollideRect(const Rect_ &other) const
    {
        return (pos.x < other.pos.x + other.width) &&
               (pos.x+width > other.pos.x) &&
               (pos.y < other.pos.y + other.height) &&
               (pos.y+height > other.pos.y);
    }
    bool IsContainedIn(const Rect_& other) const
    {
        return (pos.x >= other.pos.x) &&
               (pos.y >= other.pos.y) &&
               (pos.x + width <= other.pos.x + other.width) &&
               (pos.y + height <= other.pos.y + other.height);
    }
    Collision IsCollideWindow(const Rect_<int>& windowRect) const
    {
        unsigned char collisionType = 0;
        
        if( pos.x < windowRect.Left() )
            collisionType |= (unsigned char)Collision::Left;
        if( pos.x + width > windowRect.Right() )
            collisionType |= (unsigned char)Collision::Right;
        if(pos.y < windowRect.Top())
            collisionType |= (unsigned char)Collision::Top;
        if( pos.y + height > windowRect.Bottom() )
            collisionType |= (unsigned char)Collision::Bottom;
        
        return Collision(collisionType);
    }
public:
    T Left() const
    {
        return pos.x;
    }
    T Right() const
    {
        return pos.x + width - 1;
    }
    T Top() const
    {
        return pos.y;
    }
    T Bottom() const
    {
        return pos.y + height - 1;
    }
public:
    constexpr Rect_ GetExpanded(T offset) const
    {
        return Rect_( Vec2_<T> { pos.x - offset, pos.y - offset } , width + offset * 2, height + offset * 2);
    }
    constexpr Vec2_<T> GetCenter() const
    {
        return Vec2_<T>{pos.x + (width + 1) / 2, pos.y + (height + 1) / 2};
    }
};

using Rect = Rect_<double>;
using RectI = Rect_<int>;
