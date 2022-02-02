#include "Vec2.hpp"
#include <cmath>

Vec2::Vec2():x(0.0),y(0.0){}

Vec2::Vec2(double ox, double oy):x(ox),y(oy){}

Vec2::Vec2(const Vec2& other):x(other.x),y(other.y){}

Vec2  Vec2::operator+(const Vec2& other)const{return Vec2(x+other.x,y+other.y);}

Vec2  Vec2::operator-(const Vec2& other)const{return Vec2(x-other.x,y-other.y);}

Vec2  Vec2::operator*(double k)const{return Vec2(x*k,y*k);}

Vec2  Vec2::operator/(double k)const{return Vec2(x/k,y/k);}

Vec2& Vec2::operator=(const Vec2& other){x = other.x; y = other.y; return *this;}

Vec2& Vec2::operator+=(const Vec2& other){return *this = (*this)+other;}

Vec2& Vec2::operator-=(const Vec2& other){return *this = (*this)-other;}

Vec2& Vec2::operator*=(double k){return *this = (*this)*k;}

Vec2& Vec2::operator/=(double k){return *this = (*this)/k;}

double Vec2::GetLengthSq() const{return x*x + y*y;}

double Vec2::GetLength() const{return std::sqrt(GetLengthSq());}

Vec2& Vec2::Normalize(){return *this = this->GetNormalized();}

Vec2 Vec2::GetNormalized() const{
    if(GetLength() != 0.0)
        return (*this)/GetLength();
    else return Vec2(0,0);
}



