#pragma once

#include "Simulation.h"
#include <vector>

// Gets the number of rolls until a given sequence of numbers have been rolled
class RollAllFaces : public Simulation
{

    bool conditionMet(std::vector<bool>& rolls);
public:
    RollAllFaces();
    RollAllFaces(const std::uniform_int_distribution<>& die);

    int runSample(std::mt19937& mt);
};