//
// Created by polydome on 4/25/20.
//

#include "AddOrganismPresenter.h"
#include "domain/organism/OrganismType.h"
#include "presentation/common/GridUtils.h"

AddOrganismPresenter::AddOrganismPresenter(Simulation &simulation, ApplicationStore& store)
    : simulation(simulation), store(store) {}

std::string entityTypeToString(OrganismType type) {
    switch (type) {
        case HUMAN: return "Human";
        case VIRUS: return "Virus";
        default: return "UNIMPLEMENTED_OPTION";
    }
}

string AddOrganismPresenter::getOptionAt(int position) {
    return entityTypeToString(static_cast<OrganismType>(position));
}

void AddOrganismPresenter::addSelectedOrganism(int position) {
    if (store.getState().selectedTile < 0)
        return;

    Coordinates coords = indexToCoordinates(store.getState().selectedTile);
    simulation.spawnEntity(static_cast<OrganismType>(position), coords.x, coords.y);

    store.notifyOrganismCreated();
}

int AddOrganismPresenter::getOptionsCount() {
    return OrganismType::_LENGTH;
}