//
// Created by polydome on 4/28/20.
//

#include "SimulationControlsPresenter.h"

SimulationControlsPresenter::SimulationControlsPresenter(Simulation &simulation, ApplicationStore &store)
        : simulation(simulation), store(store) {}

void SimulationControlsPresenter::tick() {
    simulation.tick();
    store.notifySimulationTicked();
}
