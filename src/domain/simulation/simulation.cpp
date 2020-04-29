#include "simulation.h"
#include "domain/organism/organism.h"
#include "domain/logging/ekolog.h"
#include <cassert>
#include "domain/organism/spawn.h"

void Simulation::spawnEntity(OrganismType type, int x, int y) {
    spawn(type, organismRepository, x, y);
}

void Simulation::tick() {
    const std::set<Organism*> organismsInSimulation = organismRepository.getAll();

    for (auto organism : organismsInSimulation) {
        Vicinity* vicinity = vicinityProvider.provideFor(*dynamic_cast<Body*>(organism));

        assert (vicinity != nullptr);

        if (organism->isAlive()) {
            Ekolog::getInstance().tick(*organism);
            organism->onTick(*vicinity);
        } else {
            organism->onDecomposition();
        }
    }

    cleanUp(organismsInSimulation);
}

void Simulation::cleanUp(const std::set<Organism*> &organismsInSimulation) {
    for (auto organism : organismsInSimulation) {
        if (organism->getMass() == 0) {
            organismRepository.removeById(organism->getId());
            Ekolog::getInstance().decomposed(*organism);
        }
    }
}
