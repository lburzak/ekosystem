#include "simulation.h"
#include "domain/organism/organism.h"
#include "domain/logging/ekolog.h"
#include <cassert>
#include "domain/organism/spawn.h"

void Simulation::spawnEntity(OrganismType type, int x, int y) {
    spawn(type, bodyRepository, x, y);
}

std::set<Organism*> filterOrganisms(const std::set<Body*>& bodies) {
    std::set<Organism*> organisms;

    Organism* organism;
    for (auto body : bodies)
        if ((organism = dynamic_cast<Organism*>(body)))
            organisms.insert(organism);

    return organisms;
}

void Simulation::tick() {
    const std::set<Organism*> organisms = filterOrganisms(bodyRepository.getAll());

    for (auto organism : organisms) {
        Vicinity* vicinity = vicinityProvider.provideFor(*organism);

        assert (vicinity != nullptr);

        if (organism->isAlive()) {
            Ekolog::getInstance().tick(*organism);
            organism->onTick(*vicinity);
        } else {
            organism->onDecomposition();
        }
    }

    cleanUp(organisms);
}

void Simulation::cleanUp(const std::set<Organism*> &organismsInSimulation) {
    for (auto organism : organismsInSimulation) {
        if (organism->getMass() == 0) {
            bodyRepository.removeById(organism->getId());
            Ekolog::getInstance().decomposed(*organism);
        }
    }
}
