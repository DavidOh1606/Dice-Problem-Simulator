#include "Simulation.h"

#include <iostream>

Simulation::Simulation(const std::string& valueName, const std::string& totalValueName, const std::uniform_int_distribution<>& die)
    : m_die{die}, m_valueName{valueName}, m_totalValueName{totalValueName}
{

}

std::string& Simulation::valueName()
{
    return m_valueName;
}

std::string& Simulation::totalValueName()
{
    return m_totalValueName;
}