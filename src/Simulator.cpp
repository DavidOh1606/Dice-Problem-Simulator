#include "Simulator.h"
#include "RollToSequence.h"

#include <iostream>

Simulator::Simulator()
{
    
}

void Simulator::runSimulation(Simulation& simulation, int numSamples, bool printSamples)
{
    float total { 0 };

    for (int i { 0 }; i < numSamples; i++)
    {
        int numRolls = simulation.runSample(mt);
        total += numRolls;

        if (printSamples)
        {
            std::cout << "Sample: " << i << '\t' << simulation.valueName() << ": " << numRolls << "\n\n";
        }
    }

    std::cout << simulation.totalValueName() << ": " << (total / numSamples) << '\n';
}