#pragma once

#include "Expected.h"


class RollToSequence : public Expected
{

std::vector<int> m_sequence;
bool conditionMet(std::deque<int>& rolls);
public:
    RollToSequence(std::vector<int> m_sequence);
    RollToSequence(std::vector<int> m_sequence, std::uniform_int_distribution<> die);

    int runSample(std::mt19937& mt);
};