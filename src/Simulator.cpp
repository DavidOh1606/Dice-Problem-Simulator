#include "Simulator.h"
#include "RollToSequence.h"

#include <iostream>

Simulator::Simulator()
{
    
}

void Simulator::runSimulation(Simulation& expected, int numSamples, bool printSamples)
{
    float total { 0 };

    for (int i { 0 }; i < numSamples; i++)
    {
        int numRolls = expected.runSample(mt);
        total += numRolls;

        if (printSamples)
        {
            std::cout << "Sample: " << i << '\t' << expected.valueName() << ": " << numRolls << "\n\n";
        }
    }

    std::cout << "Total Average " << expected.valueName() << ": " << (total / numSamples) << '\n';


}