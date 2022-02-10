#include "Timer.hpp"

Timer::Timer() : m_beg(clock_t::now())
{
}

void Timer::Reset(){
    m_beg = clock_t::now();
}

double Timer::Elapsed() const{
    return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
}

double Timer::Mark(){
    std::chrono::time_point<clock_t> temp = m_beg;
    Reset();
    return std::chrono::duration_cast<second_t>(m_beg - temp).count();
}
