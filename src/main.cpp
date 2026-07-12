#include <iostream>
#include "Simulator.h"
#include "Expected.h"
#include <random>
#include <deque>

int main()
{

    std::vector<int> condition;

    condition.push_back(1);
    condition.push_back(2);


    Expected expected { condition, std::uniform_int_distribution<>{1, 6} };

    Simulator sim;

    sim.runSimulation(expected, 10000, true);

    return 0;
}