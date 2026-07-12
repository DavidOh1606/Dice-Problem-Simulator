#include "Simulator.h"

#include <iostream>

Simulator::Simulator()
{
    std::uniform_int_distribution<> die6{ 1, 6 };
    std::cout << die6(mt) << '\n';
}