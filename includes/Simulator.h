#pragma once

#include <random>

#include "Simulation.h"
#include <memory>


class Simulator
{
    std::random_device rd{};
    std::seed_seq seed{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937 mt{ seed };



public:
    Simulator();

    void runSimulation(std::shared_ptr<Simulation> simulation, int numSamples, bool printSamples);
};