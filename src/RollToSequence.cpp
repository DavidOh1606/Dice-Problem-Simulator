
#include "RollToSequence.h"
#include <iostream>


RollToSequence::RollToSequence(const std::vector<int>& sequence)
    : RollToSequence(sequence, std::uniform_int_distribution<> { 1, 6 })
{

}

RollToSequence::RollToSequence(const std::vector<int>& sequence, 
                        const std::uniform_int_distribution<>& die)
    : Simulation("Num Rolls", "Average Num Rolls", die), m_sequence{sequence}
{
    for (int i : m_sequence)
    {
        if (i < m_die.min() || i > m_die.max())
        {
            std::cerr << "Condition contains value outside die range" << '\n';
            exit(-1);
        }
    }
}

int RollToSequence::runSample(std::mt19937& mt)
{


    int roll { 0 };
    int rollCount { 0 };

    std::deque<int> rolls;


    while (!conditionMet(rolls))
    {
        rollCount++;
        roll = m_die(mt);

        rolls.push_back(roll);

        if (rolls.size() > m_sequence.size())
        {
            rolls.pop_front();
        }
    }   

    return rollCount;
}

bool RollToSequence::conditionMet(std::deque<int>& rolls)
{
    if (rolls.size() != m_sequence.size())
    {
        return false;
    }

    for (int i { 0 }; i < m_sequence.size(); i++)
    {

        if (rolls[i] != m_sequence[i])
        {
            return false;
        }
    }

    return true;
}