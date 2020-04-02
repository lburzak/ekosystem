#include "organism.h"


void Organism::onDecomposition() {
    if (isAlive() && mass > 0) {
        mass--;
    }
}
