#include "iostream"
#include "organism.h"

#include <logging/ekolog.h>


void Organism::onDecomposition() {
    if (!isAlive() && mass > 0) {
        mass--;
        Ekolog::getInstance().organism(*this);
    }
}

InfoBundle Organism::bundleInfo() {
    InfoBundle bundle;

    bundle.set("alive", to_string(alive));
    bundle.set("massLeft", to_string(mass));

    return bundle;
}
