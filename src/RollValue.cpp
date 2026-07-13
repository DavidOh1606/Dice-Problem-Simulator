#include "RollValue.h"

RollValue::RollValue(int numDie)
    : RollValue(numDie, std::uniform_int_distribution<> { 1, 6 })
{

}

RollValue::RollValue(int numDie, const std::uniform_int_distribution<>& die)
    : Simulation("Sum of Rolls", die), m_numDie{numDie}
{

}

int RollValue::runSample(std::mt19937& mt)
{
    int value = 0;

    for (int i { 0 }; i < m_numDie; i++)
    {
        int roll = m_die(mt);

        value += roll;
    }

    return value;
}