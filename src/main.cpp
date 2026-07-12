#include <iostream>
#include "Simulator.h"
#include "Expected.h"
#include "RollToSequence.h"
#include "RollValue.h"
#include <random>
#include <deque>

int main()
{

    std::vector<int> condition;

    condition.push_back(1);
    condition.push_back(2);
    condition.push_back(3);


    RollToSequence expected { condition };
    RollValue value { 1 };


    Simulator sim;

    // sim.runSimulation(value, 40000, true);
    sim.runSimulation(expected, 40000, true);

    return 0;
}