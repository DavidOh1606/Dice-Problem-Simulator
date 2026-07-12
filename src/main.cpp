#include <iostream>
#include "Dice.h"
#include "Simulator.h"

int main()
{
    std::cout << "Hello world!!" << '\n';
    Simulator sim;
    Dice dice{};
    dice.print();
    return 0;
}