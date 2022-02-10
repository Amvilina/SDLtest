#include "Random.hpp"

Random::Random(){
    std::random_device rd;
    mt.seed(rd());
}

double Random::GetDouble(double min, double max){
    std::uniform_real_distribution<double> dist(min, max);
    return dist(mt);
}
dVec2 Random::GetDoubleVec2(double min1, double max1, double min2, double max2){
    return dVec2(GetDouble(min1, max1), GetDouble(min2, max2));
}
dVec2 Random::GetDoubleVec2(double min, double max){
    return dVec2(GetDouble(min, max), GetDouble(min, max));
}

int Random::GetInt(int min, int max){
    std::uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}
iVec2 Random::GetIntVec2(int min1, int max1, int min2, int max2){
    return iVec2(GetInt(min1, max1), GetInt(min2, max2));
}
iVec2 Random::GetIntVec2(int min, int max){
    return iVec2(GetInt(min, max), GetInt(min, max));
}
