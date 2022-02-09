#pragma once
#include <random>

class Random{
public:
    Random();
    //double GetDouble(double min, double max);
    int GetInt(int min, int max);
private:
    std::mt19937 mt;
};

