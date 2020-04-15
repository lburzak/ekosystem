//
// Created by polydome on 4/15/20.
//

#include "GridUtils.h"

Coordinates indexToCoordinates(int index) {
    return { index % Space::WIDTH, index / Space::WIDTH };
}