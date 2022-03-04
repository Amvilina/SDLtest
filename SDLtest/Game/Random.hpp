#pragma once
#include <random>
#include "Vec2_.hpp"

template <class T>
class Random{
public:
    Random()
    {
        std::random_device rd;
        mt.seed(rd());
    }
public:
    T Get(T min, T max)
    {
        std::uniform_real_distribution<double> dist(min, max);
        return T( dist(mt) );
    }
    Vec2_<T> GetVec2(T min1, T max1, T min2, T max2)
    {
        return Vec2_<T>{ Get(min1, max1), Get(min2, max2) };
    }
    Vec2_<T> GetVec2(T min, T max)
    {
        return GetVec2(min, max, min, max);
    }
private:
    std::mt19937 mt;
};


