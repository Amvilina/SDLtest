#include "iVec2.hpp"
#include <cmath>

iVec2  iVec2::operator+(const iVec2& other)const{return iVec2(x+other.x,y+other.y);}

iVec2  iVec2::operator-(const iVec2& other)const{return iVec2(x-other.x,y-other.y);}

iVec2  iVec2::operator*(int k)const{return iVec2(x*k,y*k);}

iVec2 iVec2::operator/(int k)const{return iVec2(x/k,y/k);;}

iVec2& iVec2::operator=(const iVec2& other){x = other.x; y = other.y; return *this;}

iVec2& iVec2::operator+=(const iVec2& other){return *this = (*this)+other;}

iVec2& iVec2::operator-=(const iVec2& other){return *this = (*this)-other;}

iVec2& iVec2::operator*=(int k){return *this = (*this)*k;}

bool iVec2::operator==(const iVec2& other) const{return x==other.x && y==other.y;}

bool iVec2::operator!=(const iVec2& other) const{return !(*this==other);}

int iVec2::GetLengthSq() const{return x*x + y*y;}

double iVec2::GetLength() const{return std::sqrt(GetLengthSq());}

iVec2::operator dVec2() const{return dVec2(x,y);}
