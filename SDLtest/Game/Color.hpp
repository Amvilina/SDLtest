#pragma once
#include <cstdint>
class Color{
public:
    Color();
    Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255);
    Color(const Color& other);
    
    void SetColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255);
    void SetColor(const Color& other);
    
    void SetR(std::uint8_t value);
    void SetG(std::uint8_t value);
    void SetB(std::uint8_t value);
    void SetA(std::uint8_t value);
    
    std::uint8_t GetR() const;
    std::uint8_t GetG() const;
    std::uint8_t GetB() const;
    std::uint8_t GetA() const;

    
private:
    std::uint8_t R;
    std::uint8_t G;
    std::uint8_t B;
    std::uint8_t A;
};
