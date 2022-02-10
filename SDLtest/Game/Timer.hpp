#pragma once
#include <chrono>

class Timer
{
public:
    Timer();
    
    void Reset();
    double Elapsed() const;
    double Mark();
    
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double>;
    std::chrono::time_point<clock_t> m_beg;
};
