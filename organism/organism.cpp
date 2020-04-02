#include "iostream"
#include "organism.h"


void Organism::onDecomposition() {
    if (!isAlive() && mass > 0) {
        mass--;
        std::cout << "massleft=" << mass << std::endl;
    }
}
