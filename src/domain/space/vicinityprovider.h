#ifndef VICINITYPROVIDER_H
#define VICINITYPROVIDER_H

#include "vicinity.h"


class VicinityProvider {
public:
    VicinityProvider(Space& space, BodyRepository &bodyRepository, RandomNumberGenerator& rng);

    Vicinity* provideFor(unsigned int bodyId);

private:
    Space& space;
    BodyRepository& bodyRepository;
    RandomNumberGenerator& rng;
};

#endif // VICINITYPROVIDER_H
