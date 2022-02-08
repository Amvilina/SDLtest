#pragma once
#include <cstdint>

class Color{
public:
    Color();
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
    Color(const Color& other);
    
    void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
    void SetColor(const Color& other);
    
    void SetR(uint8_t val);
    void SetG(uint8_t val);
    void SetB(uint8_t val);
    void SetA(uint8_t val);
    
    uint8_t GetR() const;
    uint8_t GetG() const;
    uint8_t GetB() const;
    uint8_t GetA() const;

    uint32_t value;
};
