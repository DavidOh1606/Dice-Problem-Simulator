#include "Expected.h"

#include <iostream>


Expected::Expected(const std::vector<int>& condition, const std::uniform_int_distribution<>& die)
    : m_condition(condition), m_die{die}
{
    for (int i : m_condition)
    {
        if (i < m_die.min() || i > m_die.max())
        {
            std::cerr << "Condition contains value outside die range" << '\n';
            exit(-1);
        }
    }
}

int Expected::runSample(std::mt19937& mt)
{


    int roll { 0 };
    int rollCount { 0 };

    std::deque<int> rolls;


    while (!conditionMet(rolls))
    {
        rollCount++;
        roll = m_die(mt);

        rolls.push_back(roll);

        if (rolls.size() > m_condition.size())
        {
            rolls.pop_front();
        }
    }   

    return rollCount;
}

bool Expected::conditionMet(std::deque<int>& rolls)
{
    if (rolls.size() != m_condition.size())
    {
        return false;
    }

    for (int i { 0 }; i < m_condition.size(); i++)
    {

        if (rolls[i] != m_condition[i])
        {
            return false;
        }
    }

    return true;
}