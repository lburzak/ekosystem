//
// Created by polydome on 4/15/20.
//

#include "domain/organism/organism.h"

Coordinates indexToCoordinates(int index) {
    return { index % Space::WIDTH, index / Space::WIDTH };
}

Organism* fetchOrganismAt(Space& space, int tileIndex, int organismIndex) {
    if (organismIndex < 0 or tileIndex < 0)
        return nullptr;

    Coordinates coords = indexToCoordinates(tileIndex);
    set<Body*> bodies = space.getBodiesAt(coords.x, coords.y);

    auto it = bodies.begin();
    for (int i = 0; i < organismIndex; i++)
        if (it == bodies.end())
            return nullptr;
        else
            it++;

    if (auto* organism = dynamic_cast<Organism*>((*it)))
        return organism;
    else
        return nullptr;
}