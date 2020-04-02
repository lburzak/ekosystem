#ifndef ORGANISM_H
#define ORGANISM_H

#include <space/vicinity.h>



class Organism : public Body {
public:
    virtual void onTick(Vicinity vicinity) = 0;
};

#endif // ORGANISM_H
