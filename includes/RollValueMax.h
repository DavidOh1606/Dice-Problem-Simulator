#pragma once

#include "Simulation.h"

// Gets the sum of n die rolled
class RollValueMax : public Simulation
{
    int m_numDie;

public:
    RollValueMax(int numDie);
    RollValueMax(int numDie, const std::uniform_int_distribution<>& die);

    int runSample(std::mt19937& mt);
};