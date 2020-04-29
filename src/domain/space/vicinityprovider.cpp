#include "vicinityprovider.h"


VicinityProvider::VicinityProvider(Space &space, BodyRepository &bodyRepository, RandomNumberGenerator& rng)
: space(space), bodyRepository(bodyRepository), rng(rng) {}

Vicinity* VicinityProvider::provideFor(unsigned int bodyId) {
    Coordinates* coords = space.locate(bodyId);

    if (coords != nullptr) {
        return new Vicinity(space, coords->x, coords->y, bodyId, bodyRepository, rng);
    } else {
        return nullptr;
    }
}
