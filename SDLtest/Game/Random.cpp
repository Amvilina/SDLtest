#include "Random.hpp"

Random::Random(){
    std::random_device rd;
    mt.seed(rd());
}

int Random::GetInt(int min, int max){
    std::uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}
