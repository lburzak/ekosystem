//
// Created by polydome on 4/29/20.
//

#include "BodyRepository.h"

BodyRepository::BodyRepository(Space &space, BodyRegistry &bodyRegistry)
    : space(space), registry(bodyRegistry) {}

std::set<Body *> BodyRepository::getAll() {
    std::set<Body*> allBodies;

    for (int i = 0; i < Space::WIDTH; i++)
        for (int j = 0; j < Space::HEIGHT; j++)
            for (const auto body : space.getBodiesAt(i, j))
                allBodies.insert(body);

    return allBodies;
}

void BodyRepository::removeById(unsigned int id) {
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

void BodyRepository::insert(Body &body, int x, int y) {
    registry.registerBody(body);
    space.putAt(body, x, y);
}
