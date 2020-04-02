#ifndef HUMAN_H
#define HUMAN_H

#include "organism.h"
#include <iostream>
#include <body/body.h>

using namespace std;

class Human : public Organism {
public:
    Human() : Organism(1000) {}
    void onTick(Vicinity vicinity) override;
    void eat();
};

#endif // HUMAN_H
