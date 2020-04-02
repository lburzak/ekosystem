#ifndef VICINITYPROVIDER_H
#define VICINITYPROVIDER_H

#include "vicinity.h"



class VicinityProvider {
public:
    VicinityProvider(Space& space) : space(space) {}

    Vicinity* provideFor(Body& body) {
        Coordinates* coords = space.locate(body.id);

        if (coords != nullptr) {
            return new Vicinity(space, coords->x, coords->y, body.getId());
        } else {
            return nullptr;
        }
    }

private:
    Space& space;
};

#endif // VICINITYPROVIDER_H
