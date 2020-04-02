#include "vicinityprovider.h"


Vicinity* VicinityProvider::provideFor(Body& body) {
    Coordinates* coords = space.locate(body.id);

    if (coords != nullptr) {
        return new Vicinity(space, coords->x, coords->y, body.getId());
    } else {
        return nullptr;
    }
}
