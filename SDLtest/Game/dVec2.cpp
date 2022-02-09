#include "dVec2.hpp"
#include <cmath>

dVec2::dVec2():x(0.0),y(0.0){}

dVec2::dVec2(double x, double y):x(x),y(y){}

dVec2::dVec2(const dVec2& other):x(other.x),y(other.y){}

dVec2  dVec2::operator+(const dVec2& other)const{return dVec2(x+other.x,y+other.y);}

dVec2  dVec2::operator-(const dVec2& other)const{return dVec2(x-other.x,y-other.y);}

dVec2  dVec2::operator*(double k)const{return dVec2(x*k,y*k);}

dVec2  dVec2::operator/(double k)const{return dVec2(x/k,y/k);}

dVec2& dVec2::operator=(const dVec2& other){x = other.x; y = other.y; return *this;}

dVec2& dVec2::operator+=(const dVec2& other){return *this = (*this)+other;}

dVec2& dVec2::operator-=(const dVec2& other){return *this = (*this)-other;}

dVec2& dVec2::operator*=(double k){return *this = (*this)*k;}

dVec2& dVec2::operator/=(double k){return *this = (*this)/k;}

bool dVec2::operator==(const dVec2& other) const{return IsEqual(x, other.x) && IsEqual(y, other.y);}

bool dVec2::operator!=(const dVec2& other) const{return !(*this==other);}

double dVec2::GetLengthSq() const{return x*x + y*y;}

double dVec2::GetLength() const{return std::sqrt(GetLengthSq());}

dVec2& dVec2::Normalize(){return *this = this->GetNormalized();}

dVec2 dVec2::GetNormalized() const{
    if(GetLength() != 0.0)
        return (*this)/GetLength();
    else return dVec2(0,0);
}

dVec2::operator iVec2() const{return iVec2(x,y);}

bool dVec2::IsEqual(double a, double b) const{
    
    double diff = fabs(a - b);
    
    if (diff <= 10e-12)
        return true;
 
    return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * 10e-9);
}

