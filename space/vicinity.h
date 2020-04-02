#ifndef VICINITY_H
#define VICINITY_H

#include "direction.h"
#include "space.h"
#include "body/body.h"
#include <set>


class Vicinity {
public:
    Vicinity(Space& space, int x, int y, unsigned ownerBodyId) : space(space) {
        this->x = x;
        this->y = y;
        this->ownerBodyId = ownerBodyId;
    }

    bool canMoveTo(Direction direction) {
        return direction == Direction::UP;
    }

    std::set<Body*> getBodies() {
        std::set<Body*> bodies = space.getBodiesAt(x, y);

        for (auto it = bodies.begin(); it != bodies.end(); it++) {
            if ((*it)->getId() == ownerBodyId) {
                bodies.erase(it);
                break;
            }
        }

        return bodies;
    };

private:
    Space& space;
    std::set<Body*> bodies;
    int x;
    int y;
    unsigned ownerBodyId;
};

#endif // VICINITY_H
