#include "iostream"
#include "organism.h"

#include <logging/ekolog.h>


void Organism::onDecomposition() {
    if (!isAlive() && mass > 0) {
        mass--;
        Ekolog::getInstance().organism(*this);
    }
}
