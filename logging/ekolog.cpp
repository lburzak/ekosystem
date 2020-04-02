#include "ekolog.h"
#include <iostream>

using namespace std;


Ekolog* Ekolog::instance = nullptr;

Ekolog& Ekolog::getInstance() {
    if (Ekolog::instance == nullptr) {
        Ekolog::instance = new Ekolog;
    }

    return *Ekolog::instance;
}

void Ekolog::organism(Organism& organism) {
    cout << organism.getId() << "\t" << organism.bundleInfo().toString() << endl;
}

void Ekolog::decomposed(Organism& organism) {
    cout << "DECOMPOSED\tID=" << organism.getId() << endl;
}

void Ekolog::tick(Organism& organism) {
    cout << "TICK\t\tID=" << organism.getId() << "\t" << organism.bundleInfo().toString() << endl;
}

void Ekolog::decomposing(Organism &organism, unsigned fromMass, unsigned toMass) {
    cout << "DECOMPOSING\tID=" << organism.getId() << "\t" << fromMass << " -> " << toMass << endl;
}

void Ekolog::death(Organism &organism) {
    cout << "DEATH\t\tID=" << organism.getId() << endl;
}
