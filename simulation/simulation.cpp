#include "simulation.h"
#include <organism/human.h>
#include <organism/virus.h>
#include <assert.h>

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
        (*it)->onTick(*vicinity);
    }
}
