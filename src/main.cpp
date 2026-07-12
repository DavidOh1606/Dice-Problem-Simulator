#include <iostream>
#include "Simulator.h"
#include "Expected.h"
#include "RollToSequence.h"
#include <random>
#include <deque>

int main()
{

    std::vector<int> condition;

    condition.push_back(1);
    condition.push_back(2);
    condition.push_back(3);


    RollToSequence expected { condition };

    Simulator sim;

    sim.runSimulation(expected, 40000, true);

    return 0;
}