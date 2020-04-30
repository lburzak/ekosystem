#include "vicinity.h"
#include "domain/organism/spawn.h"
#include "cmath"

bool Vicinity::canMoveTo(Direction direction) {
    return direction == Direction::UP;
}

std::set<Body*> Vicinity::getBodies() {
    std::set<Body*> bodies = bodyRepository.getAt(x, y);

    for (auto it = bodies.begin(); it != bodies.end(); it++) {
        if ((*it)->getId() == ownerBodyId) {
            bodies.erase(it);
            break;
        }
    }

    return bodies;
}

Vicinity::Vicinity(Space &space, int x, int y, unsigned int ownerBodyId, BodyRepository &bodyRepository, RandomNumberGenerator& rng)
: space(space), x(x), y(y), ownerBodyId(ownerBodyId), bodyRepository(bodyRepository), rng(rng) {}

void Vicinity::spawnNear(OrganismType type) {
    spawn(type, bodyRepository, x, y);
}

Coordinates randomCoordinatesNear(int x, int y, int range, int maxX, int maxY, RandomNumberGenerator& rng) {
    Coordinates candidate = {
            x + rng.getInt(-range, range),
            y + rng.getInt(-range, range)
    };

    if (candidate.x < 0)
        candidate.x = 0;

    if (candidate.y < 0)
        candidate.y = 0;

    if (candidate.x >= maxX)
        candidate.x = maxX;

    if (candidate.y >= maxY)
        candidate.y = maxY;

    return candidate;
}

void Vicinity::applyForce(int value) {
    std::set<Body*> bodies = bodyRepository.getAt(x, y);
    Coordinates coordinates{};
    for (auto body : bodies) {
        if (body->getMass() < value) {
            coordinates = randomCoordinatesNear(x, y, 1, Space::WIDTH - 1, Space::HEIGHT - 1, rng);
            bodyRepository.move(body->getId(), coordinates.x, coordinates.y);
        }
    }
}
