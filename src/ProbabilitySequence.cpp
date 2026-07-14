
#include "ProbabilitySequence.h"
#include <iostream>


ProbabilitySequence::ProbabilitySequence(const std::vector<int>& sequence, int numRolls)
    : ProbabilitySequence(sequence, numRolls, std::uniform_int_distribution<> { 1, 6 })
{

}

ProbabilitySequence::ProbabilitySequence(const std::vector<int>& sequence, int numRolls,
                        const std::uniform_int_distribution<>& die)
    : Simulation("Sequence was rolled", "Probability", die), m_sequence{sequence}, m_numRolls(numRolls)
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

int ProbabilitySequence::runSample(std::mt19937& mt)
{

    int rollCount { 0 };

    std::deque<int> rolls;


    while (!conditionMet(rolls) && rollCount < m_numRolls)
    {
        rollCount++;
        int roll = m_die(mt);

        rolls.push_back(roll);

        if (rolls.size() > m_sequence.size())
        {
            rolls.pop_front();
        }
    }   

    if (conditionMet(rolls))
    {
        return 1;
    }


    return 0;
}

bool ProbabilitySequence::conditionMet(std::deque<int>& rolls)
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