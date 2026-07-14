
#include "RollValueMax.h"
#include <iostream>

RollValueMax::RollValueMax(int numDie)
    : RollValueMax(numDie, std::uniform_int_distribution<> { 1, 6 })
{

}

RollValueMax::RollValueMax(int numDie, const std::uniform_int_distribution<>& die)
    : Simulation("Max Roll", "Average of Max Rolls", die), m_numDie{numDie}
{
    if (numDie <= 0)
    {
        std::cerr << "Number of die should be 1 or greater\n";
        exit(1);
    }
}

int RollValueMax::runSample(std::mt19937& mt)
{
    int value { m_die(mt) };


    for (int i { 1 }; i < m_numDie; i++)
    {
        int roll = m_die(mt);

        if (roll > value)
        {
            value = roll;
        }
    }

    return value;
}