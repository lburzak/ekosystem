//
// Created by polydome on 4/28/20.
//

#ifndef EKOSYSTEM_SIMULATIONCONTROLSPRESENTER_H
#define EKOSYSTEM_SIMULATIONCONTROLSPRESENTER_H

#include "domain/simulation/simulation.h"
#include "presentation/state/ApplicationStore.h"

class SimulationControlsPresenter {
public:
    SimulationControlsPresenter(Simulation &simulation, ApplicationStore &store);
    void tick();

private:
    Simulation& simulation;
    ApplicationStore& store;
};


#endif //EKOSYSTEM_SIMULATIONCONTROLSPRESENTER_H
