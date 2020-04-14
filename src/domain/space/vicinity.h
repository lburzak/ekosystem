#ifndef VICINITY_H
#define VICINITY_H

#include "direction.h"
#include "space.h"
#include "domain/body/body.h"
#include <set>


class Vicinity {
public:
    Vicinity(Space& space, int x, int y, unsigned ownerBodyId)
        : space{ space },
          x{ x },
          y{ y },
          ownerBodyId{ ownerBodyId }
    {}

    bool canMoveTo(Direction direction);
    std::set<Body*> getBodies();

private:
    Space& space;
    std::set<Body*> bodies;
    int x;
    int y;
    unsigned ownerBodyId;
};

#endif // VICINITY_H
