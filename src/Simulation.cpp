#include "Simulation.h"

#include <iostream>

Simulation::Simulation(const std::string& valueName, const std::uniform_int_distribution<>& die)
    : m_die{die}, m_valueName{valueName}
{

}

std::string& Simulation::valueName()
{
    return m_valueName;
}