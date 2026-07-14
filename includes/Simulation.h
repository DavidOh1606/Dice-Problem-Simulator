#pragma once

#include <random>

class Simulation
{
protected:
    std::uniform_int_distribution<> m_die;
    std::string m_valueName;
    std::string m_totalValueName;

public:
    Simulation(const std::string& valueName, const std::string& totalValueName, 
               const std::uniform_int_distribution<>& die);

    virtual int runSample(std::mt19937& mt) = 0;

    std::string& valueName();
    std::string& totalValueName();

};