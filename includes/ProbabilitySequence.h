#pragma once

#include "Simulation.h"
#include <deque>

// Gets the number of rolls until a given sequence of numbers have been rolled
class ProbabilitySequence : public Simulation
{

    std::vector<int> m_sequence;
    int m_numRolls;
    bool conditionMet(std::deque<int>& rolls);
public:
    ProbabilitySequence(const std::vector<int>& m_sequence, int numRolls);
    ProbabilitySequence(const std::vector<int>& m_sequence, int numRolls, const std::uniform_int_distribution<>& die);

    int runSample(std::mt19937& mt);
};