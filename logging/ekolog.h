#ifndef EKOLOG_H
#define EKOLOG_H

#include <organism/organism.h>



class Ekolog {
public:
    static Ekolog& getInstance();
    void organism(Organism& organism);
    void decomposed(Organism& organism);
    void tick(Organism& organism);
    void decomposing(Organism& organism, unsigned fromMass, unsigned toMass);
    void death(Organism &organism);
private:
    static Ekolog* instance;
};

#endif // EKOLOG_H
