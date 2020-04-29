#include "vicinity.h"
#include "domain/organism/spawn.h"

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
}

Vicinity::Vicinity(Space &space, int x, int y, unsigned int ownerBodyId, BodyRepository &bodyRepository)
: space(space), x(x), y(y), ownerBodyId(ownerBodyId), bodyRepository(bodyRepository) {}

void Vicinity::spawnNear(OrganismType type) {
    spawn(type, bodyRepository, x, y);
}
