#pragma once

#include <random>

class Simulator
{
    std::random_device rd{};
    std::seed_seq seed{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937 mt{ seed };



public:
    Simulator();



};