#pragma once
#include <cstdint>

class Color{
public:
    uint32_t value;
public:
    constexpr Color():value(0){}
    constexpr Color(uint32_t value):value(value){}
    constexpr Color(const Color& other):value(other.value){}
    constexpr Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
    :
    value((a << 24u) | (r << 16u) | (g << 8u) | b){}
    
    
    Color& operator=(const Color& other){
        value = other.value;
        return *this;
    }
    
    constexpr unsigned char GetA() const{
        return value >> 24u;
    }
    constexpr unsigned char GetR() const{
        return (value >> 16u) & 0xFFu;
    }
    constexpr unsigned char GetG() const{
        return (value >> 8u) & 0xFFu;
    }
    constexpr unsigned char GetB() const{
        return value & 0xFFu;
    }
    
    void SetA( unsigned char a ){
        value = (value & 0xFFFFFFu) | (a << 24u);
    }
    void SetR( unsigned char r ){
        value = (value & 0xFF00FFFFu) | (r << 16u);
    }
    void SetG( unsigned char g ){
        value = (value & 0xFFFF00FFu) | (g << 8u);
    }
    void SetB( unsigned char b ){
        value = (value & 0xFFFFFF00u) | b;
    }
};


namespace Colors
{
    static constexpr Color MakeRGB( uint8_t r,uint8_t g,uint8_t b){
        return Color(r,g,b);
    }
    static constexpr Color White = MakeRGB( 255u,255u,255u );
    static constexpr Color Black = MakeRGB( 0u,0u,0u );
    static constexpr Color Gray = MakeRGB( 0x80u,0x80u,0x80u );
    static constexpr Color LightGray = MakeRGB( 0xD3u,0xD3u,0xD3u );
    static constexpr Color Red = MakeRGB( 255u,0u,0u );
    static constexpr Color Green = MakeRGB( 0u,255u,0u );
    static constexpr Color Blue = MakeRGB( 0u,0u,255u );
    static constexpr Color Yellow = MakeRGB( 255u,255u,0u );
    static constexpr Color Cyan = MakeRGB( 0u,255u,255u );
    static constexpr Color Magenta = MakeRGB( 255u,0u,255u );
}
