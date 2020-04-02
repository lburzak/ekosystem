#ifndef EKOLOG_H
#define EKOLOG_H

#include <organism/organism.h>



class Ekolog {
public:
    static Ekolog& getInstance();
    void organism(Organism& organism);
    void decomposed(Organism& organism);
private:
    static Ekolog* instance;
};

#endif // EKOLOG_H
