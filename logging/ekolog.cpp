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
    cout << organism.getId() << ": " << organism.bundleInfo().toString() << endl;
}

void Ekolog::decomposed(Organism& organism) {
    cout << organism.getId() << ": " << "decomposed!" << endl;
}
