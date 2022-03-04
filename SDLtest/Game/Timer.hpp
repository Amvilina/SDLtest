#pragma once
#include <chrono>

class Timer
{
public:
    Timer() : m_beg( clock_t::now() )
    {
    }
public:
    void Reset()
    {
        m_beg = clock_t::now();
    }
    double Elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
    double Mark()
    {
        std::chrono::time_point<clock_t> temp = m_beg;
        Reset();
        return std::chrono::duration_cast<second_t>(m_beg - temp).count();
    }
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double>;
    std::chrono::time_point<clock_t> m_beg;
};
