#ifndef VICINITYPROVIDER_H
#define VICINITYPROVIDER_H

#include "vicinity.h"


class VicinityProvider {
public:
    VicinityProvider(Space& space, BodyRepository &bodyRepository);

    Vicinity* provideFor(Body& body);

private:
    Space& space;
    BodyRepository& bodyRepository;
};

#endif // VICINITYPROVIDER_H
