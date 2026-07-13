#pragma once

#include "Simulation.h"
#include <deque>

// Gets the number of rolls until a given sequence of numbers have been rolled
class RollToSequence : public Simulation
{

    std::vector<int> m_sequence;
    bool conditionMet(std::deque<int>& rolls);
public:
    RollToSequence(const std::vector<int>& m_sequence);
    RollToSequence(const std::vector<int>& m_sequence, const std::uniform_int_distribution<>& die);

    int runSample(std::mt19937& mt);
};