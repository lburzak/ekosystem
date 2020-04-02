#ifndef VIRUS_H
#define VIRUS_H

#include "human.h"
#include "organism.h"
#include <body/body.h>
#include <space/vicinity.h>



class Virus : public Organism {
public:
    Virus() : Organism(2) {}
private:
    void onTick(Vicinity vicinity) override;
    void attack(Human* human);
    Human* victim = nullptr;
};

#endif // VIRUS_H
