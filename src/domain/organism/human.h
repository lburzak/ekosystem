#ifndef HUMAN_H
#define HUMAN_H

#include "organism.h"
#include <iostream>
#include "domain/body/body.h"

using namespace std;

class Human : public Organism {
public:
    Human() : Organism(1000) {}
    void onTick(Vicinity vicinity) override;
    void eat();

    string getVisibleName() override;
};

#endif // HUMAN_H
