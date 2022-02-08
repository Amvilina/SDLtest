#include "Color.hpp"

Color::Color():value(0){}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a){
    value = r;
    value <<= 8;
    value |= g;
    value <<= 8;
    value |= b;
    value <<= 8;
    value |= a;
}

void Color::SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a){
    value = r;
    value <<= 8;
    value |= g;
    value <<= 8;
    value |= b;
    value <<= 8;
    value |= a;
}
void Color::SetColor(const Color& other){
    value = other.value;
}

void Color::SetR(uint8_t val){
    uint32_t temp = val;
    temp <<= 24;
    uint32_t Mask = 0x00ffffff;
    value &= Mask;
    value |= temp;
}
void Color::SetG(uint8_t val){
    uint32_t temp = val;
    temp <<= 16;
    uint32_t Mask = 0xff00ffff;
    value &= Mask;
    value |= temp;
}
void Color::SetB(uint8_t val){
    uint32_t temp = val;
    temp <<= 8;
    uint32_t Mask = 0xffff00ff;
    value &= Mask;
    value |= temp;
}
void Color::SetA(uint8_t val){
    uint32_t temp = val;
    
    uint32_t Mask = 0xffffff00;
    value &= Mask;
    value |= temp;
}

uint8_t Color::GetR() const {
    uint32_t Mask = 0xff000000;
    uint32_t temp = value & Mask;
    return temp>>24;
}
uint8_t Color::GetG() const {
    uint32_t Mask = 0x00ff0000;
    uint32_t temp = value & Mask;
    return temp>>16;
}
uint8_t Color::GetB() const {
    uint32_t Mask = 0x0000ff00;
    uint32_t temp = value & Mask;
    return temp>>8;
}
uint8_t Color::GetA() const {
    uint32_t Mask = 0x000000ff;
    uint32_t temp = value & Mask;
    return temp;
}
