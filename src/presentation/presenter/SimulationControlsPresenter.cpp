//
// Created by polydome on 4/28/20.
//

#include "SimulationControlsPresenter.h"

SimulationControlsPresenter::SimulationControlsPresenter(Simulation &simulation) : simulation(simulation) {}

void SimulationControlsPresenter::tick() {
    simulation.tick();
}
