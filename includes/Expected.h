#pragma once

#include <random>
#include <vector>
#include <deque>

class Expected
{
protected:
    std::uniform_int_distribution<> m_die;

public:
    Expected();
    Expected(const std::uniform_int_distribution<>& die);

    virtual int runSample(std::mt19937& mt) = 0;

};