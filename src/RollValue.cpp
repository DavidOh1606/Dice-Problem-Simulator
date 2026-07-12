#include "RollValue.h"

RollValue::RollValue(int numDie)
    : RollValue(numDie, std::uniform_int_distribution<> { 1, 6 })
{

}

RollValue::RollValue(int numDie, const std::uniform_int_distribution<>& die)
    : Expected(die), m_numDie{numDie}
{

}

int RollValue::runSample(std::mt19937& mt)
{

    


}