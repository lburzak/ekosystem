#ifndef ORGANISM_H
#define ORGANISM_H

#include <space/vicinity.h>



class Organism : public Body {
public:
    Organism(unsigned mass) : Body(mass) {}
    virtual void onTick(Vicinity vicinity) = 0;
    void onDecomposition();
    bool isAlive() { return alive; };
private:
    bool alive = true;
};

#endif // ORGANISM_H
