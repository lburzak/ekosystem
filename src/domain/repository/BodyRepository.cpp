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

BodyRepository::FindByIdResult BodyRepository::findById(unsigned int id) {
    Coordinates* coords = space.locate(id);
    if (coords) {
        auto bodies = space.getIdsAt(coords->x, coords->y);

        int i = 0;
        auto it = bodies.begin();
        for (;it != bodies.end(); it++, i++)
            if ((*it) == id) break;

        return { *it, i, true, *coords };
    }

    return { 0, 0, false };
}

void BodyRepository::removeById(unsigned int id) {
    auto result = findById(id);
    if (result.found) {
        space.removeAt(result.coordinates.x, result.coordinates.y, result.position);
    }
}

void BodyRepository::insert(Body &body, int x, int y) {
    registry.registerBody(body);
    space.putAt(body, x, y);
}

std::set<Body *> BodyRepository::getAt(int x, int y) {
    std::set<Body*> allBodies;

    for (const auto body : space.getBodiesAt(x, y))
        allBodies.insert(body);

    return allBodies;
}

void BodyRepository::move(unsigned int id, int targetX, int targetY) {
    auto result = findById(id);
    if (result.found) {
        space.removeAt(result.coordinates.x, result.coordinates.y, result.position);
        space.putAt(result.id, targetX, targetY);
    }
}

int BodyRepository::countAt(int x, int y) {
    return getAt(x, y).size();
}
