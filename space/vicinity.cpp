#include "vicinity.h"


bool Vicinity::canMoveTo(Direction direction) {
    return direction == Direction::UP;
}

std::set<Body*> Vicinity::getBodies() {
    std::set<Body*> bodies = space.getBodiesAt(x, y);

    for (auto it = bodies.begin(); it != bodies.end(); it++) {
        if ((*it)->getId() == ownerBodyId) {
            bodies.erase(it);
            break;
        }
    }

    return bodies;
};
