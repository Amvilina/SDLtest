#pragma once
#include <random>
#include "iVec2.hpp"
#include "dVec2.hpp"

class Random{
public:
    Random();
    double GetDouble(double min, double max);
    dVec2 GetDoubleVec2(double min1, double max1, double min2, double max2);
    dVec2 GetDoubleVec2(double min, double max);
    
    int GetInt(int min, int max);
    iVec2 GetIntVec2(int min1, int max1, int min2, int max2);
    iVec2 GetIntVec2(int min, int max);
private:
    std::mt19937 mt;
};

