#pragma once

#include <random>
#include <vector>
#include <deque>

class Expected
{
protected:
    std::uniform_int_distribution<> m_die;
    std::string m_valueName;

public:
    Expected(const std::string& valueName);
    Expected(const std::string& valueName, const std::uniform_int_distribution<>& die);

    virtual int runSample(std::mt19937& mt) = 0;

    std::string& valueName();
};