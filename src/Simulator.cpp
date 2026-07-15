#include "Simulator.h"
#include "RollToSequence.h"
#include "RollValue.h"
#include "RollValueMax.h"
#include "RollAllFaces.h"
#include "ProbabilitySequence.h"

#include <iostream>
#include <sstream>

Simulator::Simulator()
{
    
}

std::shared_ptr<Simulation> Simulator::getUserSimulation()
{
    std::shared_ptr<Simulation> simulation { nullptr };

    std::cout << "Enter what kind of experiment to run:\n";

    std::cout << "1 - Expected value of rolling n die.\n";
    std::cout << "2 - Expected value of the max of n die.\n";
    std::cout << "3 - Expected number of rolls to roll a sequence of numbers.\n";
    std::cout << "4 - Expected number of rolls to roll all faces.\n";
    std::cout << "5 - Probability of rolling a sequence within n rolls.\n";

    int simulationChoice;
    std::cin >> simulationChoice;

    while (simulationChoice < 1 || simulationChoice > 5)
    {
        std::cin >> simulationChoice;
    }
    
    std::cout << "Enter min value of die:\n";

    int min;
    std::cin >> min;

    std::cout << "Enter max value of die:\n";

    int max;
    std::cin >> max;

    std::uniform_int_distribution<> die{ 1, 6 };

    while (max < min)
    {
        std::cout << "Max value should be greater than min.";
        std::cin >> max;
    }

    switch (simulationChoice)
    {
    case 1:
    {
        int n { getNumRolls() };
        simulation = std::make_shared<RollValue>(n, die);
        break;
    }
    case 2:
    {
        int n { getNumRolls() };
        simulation = std::make_shared<RollValueMax>(n, die);
        break;
    }
    case 3:
    {
        std::vector<int> sequence { getSequence() };
        simulation = std::make_shared<RollToSequence>(sequence, die);
        break;
    }
    case 4:
    {
        simulation = std::make_shared<RollAllFaces>(die);
        break;
    }    
    case 5:
    {
        int n { getNumRolls() };
        std::vector<int> sequence { getSequence() };
        simulation = std::make_shared<ProbabilitySequence>(sequence, n, die);
        break;
    }
    }

    return simulation;
}

int Simulator::getNumSamples()
{
    std::cout << "Enter number of times to run simulation:\n";
    int n;
    std::cin >> n;

    while (n < 1)
    {
        std::cout << "Number should be 1 or greater.\n";
        std::cin >> n;
    }

    return n;
}
bool Simulator::getPrintSamples()
{
    std::cout << "Print results of each sample? (y/n)\n";

    char c;

    std::cin >> c;

    while (c != 'Y' && c != 'y' && c != 'N' && c != 'n')
    {
        std::cin >> c;
    }

    if (c == 'Y' || c == 'y')
    {
        return true;
    }

    return false;
}

int Simulator::getNumRolls()
{
    std::cout << "Enter number of die to roll:\n";

    int n;
    std::cin >> n;

    while (n <= 0)
    {
        std::cout << "Number of die to roll should be positive.";
        std::cin >> n;
    }

    return n;
}

std::vector<int> Simulator::getSequence()
{

    std::cout << "Enter sequence: (enter a non-numeral to stop)\n";
    std::vector<int> sequence;

    std::string curr;

    while (std::cin >> curr)
    {
        if (curr.find_first_not_of("0123456789") != std::string::npos)
        {
            if (sequence.size() == 0)
            {
                std::cout << "Must add at least one number to sequence.\n";
                continue;
            }

            break;
        }

        int x = std::stoi(curr);
        sequence.push_back(x);
    }

    return sequence;
}

void Simulator::runSimulation(std::shared_ptr<Simulation> simulation, int numSamples, bool printSamples)
{
    float total { 0 };

    for (int i { 0 }; i < numSamples; i++)
    {
        int numRolls = simulation->runSample(mt);
        total += numRolls;

        if (printSamples)
        {
            std::cout << "Sample: " << i << '\t' << simulation->valueName() << ": " << numRolls << "\n\n";
        }
    }

    std::cout << simulation->totalValueName() << ": " << (total / numSamples) << '\n';
}