#include "Simulator.h"
#include "RollToSequence.h"

#include <iostream>

Simulator::Simulator()
{
    
}

void Simulator::runSimulation(Expected& expected, int numSamples, bool printSamples)
{
    float total { 0 };

    for (int i { 0 }; i < numSamples; i++)
    {
        int numRolls = expected.runSample(mt);
        total += numRolls;

        if (printSamples)
        {
            std::cout << "Sample: " << i << '\t' << "Num Rolls: " << numRolls << "\n\n";
        }
    }

    std::cout << "Total average rolls: " << (total / numSamples) << '\n';


}