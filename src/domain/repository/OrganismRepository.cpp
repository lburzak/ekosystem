//
// Created by polydome on 4/29/20.
//

#include "OrganismRepository.h"
#include <iostream>

std::set<Organism *> OrganismRepository::getAll() {
    std::set<Organism*> allBodies;
    Organism* organism;

    for (int i = 0; i < Space::WIDTH; i++) {
        for (int j = 0; j < Space::HEIGHT; j++) {
            for (const auto body : space.getBodiesAt(i, j)) {
                if ((organism = dynamic_cast<Organism*>(body)))
                    allBodies.insert(organism);
            }
        }
    }

    return allBodies;
}

void OrganismRepository::removeById(unsigned int id) {
    Coordinates* coords = space.locate(id);
    if (coords) {
        auto bodies = space.getIdsAt(coords->x, coords->y);

        int i = 0;
        auto it = bodies.begin();
        for (;it != bodies.end(); it++, i++)
            if ((*it) == id) break;

        if (it == bodies.end()) {
            exit(3);
        } else {
            space.removeAt(coords->x, coords->y, i);
        }
    }
}

void OrganismRepository::insert(Organism& organism, int x, int y) {
    registry.registerBody(organism);
    space.putAt(organism, x, y);
}

OrganismRepository::OrganismRepository(Space &space, BodyRegistry &bodyRegistry) : space(space), registry(bodyRegistry)
{}
