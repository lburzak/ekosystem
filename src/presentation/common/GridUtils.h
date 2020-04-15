//
// Created by polydome on 4/15/20.
//

#ifndef EKOSYSTEM_GRIDUTILS_H
#define EKOSYSTEM_GRIDUTILS_H

#include "domain/space/space.h"
#include "domain/organism/organism.h"

Coordinates indexToCoordinates(int index);
Organism* fetchOrganismAt(Space& space, int tileIndex, int organismIndex);

#endif //EKOSYSTEM_GRIDUTILS_H
