#include <iostream>
#include "Simulator.h"
#include "Simulation.h"
#include "RollToSequence.h"
#include "RollValue.h"
#include "RollValueMax.h"
#include "RollAllFaces.h"
#include "ProbabilitySequence.h"
#include <random>
#include <deque>

int main()
{

    std::vector<int> condition;

    condition.push_back(1);
    condition.push_back(2);
    // condition.push_back(2);
    // condition.push_back(3);


    // RollToSequence expected { condition };
    // RollValueMax value { 3, std::uniform_int_distribution<> { -4, -1 } };
    // RollAllFaces faces { std::uniform_int_distribution<> { 1, 2 }};
    // ProbabilitySequence prob {condition, 4, std::uniform_int_distribution<> { 1, 100 }};
    
    std::shared_ptr<Simulation> rollToSequence = std::make_shared<RollToSequence>(condition);
    std::shared_ptr<Simulation> valueMax = std::make_shared<RollValueMax>(3);
    std::shared_ptr<Simulation> faces = std::make_shared<RollAllFaces>();
    std::shared_ptr<Simulation> prob = std::make_shared<ProbabilitySequence>(condition, 10, std::uniform_int_distribution<> { 1, 100 });

    Simulator sim;

    sim.runSimulation(sim.getUserSimulation(), 40000, true);
    // sim.runSimulation(valueMax, 40000, true);
    // sim.runSimulation(faces, 40000, true);
    // sim.runSimulation(prob, 2000, true);



    return 0;
}