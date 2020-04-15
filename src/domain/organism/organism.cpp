#include "iostream"
#include "organism.h"

#include "domain/logging/ekolog.h"

const char* Organism::BUNDLE_LABEL_SPECIES = "species";

void Organism::die() {
    alive = false;
    Ekolog::getInstance().death(*this);
}

void Organism::onDecomposition() {
    if (!isAlive() && mass > 0) {
        unsigned massBefore = mass;
        unsigned massAfter = --mass;

        Ekolog::getInstance().decomposing(*this, massBefore, massAfter);
    }
}

InfoBundle Organism::bundleInfo() {
    InfoBundle bundle;

    bundle.set("alive", to_string(alive));
    bundle.set("massLeft", to_string(mass));
    bundle.set(BUNDLE_LABEL_SPECIES, "Uncategorized");

    return bundle;
}
