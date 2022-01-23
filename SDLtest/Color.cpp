#include "Color.hpp"

Color::Color():R(0),G(0),B(0),A(0){}

Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a):R(r),G(g),B(b),A(a){}

void Color::SetColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a){
    R = r;
    G = g;
    B = b;
    A = a;
}
void Color::SetColor(const Color& other){
    R = other.R;
    G = other.G;
    B = other.B;
    A = other.A;
}

void Color::SetR(std::uint8_t value){R = value;}
void Color::SetG(std::uint8_t value){G = value;}
void Color::SetB(std::uint8_t value){B = value;}
void Color::SetA(std::uint8_t value){A = value;}

std::uint8_t Color::GetR() const {return R;}
std::uint8_t Color::GetG() const {return G;}
std::uint8_t Color::GetB() const {return B;}
std::uint8_t Color::GetA() const {return A;}
