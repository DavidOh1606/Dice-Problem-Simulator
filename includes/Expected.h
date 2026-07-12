#pragma once

#include <random>
#include <vector>
#include <deque>

class Expected
{
    std::vector<int> m_condition;
    std::uniform_int_distribution<> m_die { 1, 6 };


    bool conditionMet(std::deque<int>& rolls);

public:
    Expected(const std::vector<int>& condition, const std::uniform_int_distribution<>& die);

    int runSample(std::mt19937& mt);

};