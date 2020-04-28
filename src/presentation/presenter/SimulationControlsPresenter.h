//
// Created by polydome on 4/28/20.
//

#ifndef EKOSYSTEM_SIMULATIONCONTROLSPRESENTER_H
#define EKOSYSTEM_SIMULATIONCONTROLSPRESENTER_H

#include "domain/simulation/simulation.h"

class SimulationControlsPresenter {
public:
    explicit SimulationControlsPresenter(Simulation& simulation);
    void tick();

private:
    Simulation& simulation;
};


#endif //EKOSYSTEM_SIMULATIONCONTROLSPRESENTER_H
