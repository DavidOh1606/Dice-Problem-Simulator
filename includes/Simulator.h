#pragma once

#include <random>

#include "Expected.h"


class Simulator
{
    std::random_device rd{};
    std::seed_seq seed{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937 mt{ seed };



public:
    Simulator();

    void runSimulation(Expected& expected, int numSamples, bool printSamples);
};