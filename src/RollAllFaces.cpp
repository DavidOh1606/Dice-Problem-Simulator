
#include "RollAllFaces.h"


RollAllFaces::RollAllFaces()
    : RollAllFaces(std::uniform_int_distribution<> { 1, 6 })
{

}

RollAllFaces::RollAllFaces(const std::uniform_int_distribution<>& die)
    : Simulation("Num Rolls", "Average Num Rolls", die)
{
}

int RollAllFaces::runSample(std::mt19937& mt)
{
    int numRolls { 0 };
    int numFaces { m_die.max() - m_die.min() + 1 };

    std::vector<bool> facesSeen(numFaces);

    while (!conditionMet(facesSeen))
    {
        int roll = m_die(mt);

        facesSeen[roll - m_die.min()] = true;
        numRolls++;
    }

    return numRolls;

}

bool RollAllFaces::conditionMet(std::vector<bool>& facesSeen)
{
    for (bool b : facesSeen)
    {
        if (!b)
        {
            return false;
        }
    }


    return true;
}