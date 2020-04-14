#ifndef VICINITYPROVIDER_H
#define VICINITYPROVIDER_H

#include "vicinity.h"



class VicinityProvider {
public:
    VicinityProvider(Space& space) : space(space) {}

    Vicinity* provideFor(Body& body);

private:
    Space& space;
};

#endif // VICINITYPROVIDER_H
