#ifndef VICINITY_H
#define VICINITY_H

#include "direction.h"
#include "space.h"
#include "domain/body/body.h"
#include <set>
#include "domain/organism/OrganismType.h"
#include "domain/repository/BodyRepository.h"


class Vicinity {
public:
    Vicinity(Space &space, int x, int y, unsigned ownerBodyId, BodyRepository &bodyRepository);

    bool canMoveTo(Direction direction);
    std::set<Body*> getBodies();
    void spawnNear(OrganismType type);

private:
    Space& space;
    std::set<Body*> bodies;
    BodyRepository& bodyRepository;
    int x;
    int y;
    unsigned ownerBodyId;
};

#endif // VICINITY_H
