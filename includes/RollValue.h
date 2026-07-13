#pragma once

#include "Simulation.h"

// Gets the sum of n die rolled
class RollValue : public Simulation
{
    int m_numDie;

public:
    RollValue(int numDie);
    RollValue(int numDie, const std::uniform_int_distribution<>& die);

    int runSample(std::mt19937& mt);
};