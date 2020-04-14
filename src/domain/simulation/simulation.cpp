#include "simulation.h"
#include "domain/organism/organism.h"
#include "domain/organism/virus.h"
#include "domain/organism/human.h"
#include "domain/logging/ekolog.h"
#include <cassert>


void Simulation::addOrganism(Organism* organism, int x, int y) {
    bodyRegistry.registerBody(*organism);
    space.putAt(*organism, x, y);
    organisms.insert(organism);
};

void Simulation::spawn(EntityType type, int x, int y) {
    Organism* organism;
    switch (type) {
        case EntityType::HUMAN:{
            organism = new Human();
            break;
        }
        case EntityType::VIRUS:{
            organism = new Virus();
            break;
        }
    }

    addOrganism(organism, x, y);
};

void Simulation::tick() {
    for (auto it = organisms.begin(); it != organisms.end(); it++) {
        Vicinity* vicinity = vicinityProvider.provideFor(*dynamic_cast<Body*>(*it));

        assert (vicinity != nullptr);

        if ((*it)->isAlive()) {
            Ekolog::getInstance().tick(*(*it));
            (*it)->onTick(*vicinity);
        } else {
            (*it)->onDecomposition();
        }
    }

    cleanUp();
}

void Simulation::cleanUp() {
    for (auto it = organisms.begin(); it != organisms.end();) {
        if ((*it)->getMass() == 0) {
            Ekolog::getInstance().decomposed(*(*it));
            it = organisms.erase(it);
        } else {
            it++;
        }
    }
}
