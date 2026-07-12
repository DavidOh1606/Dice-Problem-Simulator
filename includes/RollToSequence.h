#pragma once

#include "Expected.h"

// Gets the number of rolls until a given sequence of numbers have been rolled
class RollToSequence : public Expected
{

    std::vector<int> m_sequence;
    bool conditionMet(std::deque<int>& rolls);
public:
    RollToSequence(const std::vector<int>& m_sequence);
    RollToSequence(const std::vector<int>& m_sequence, const std::uniform_int_distribution<>& die);

    int runSample(std::mt19937& mt);
};