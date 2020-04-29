#include "vicinityprovider.h"


VicinityProvider::VicinityProvider(Space &space, BodyRepository &bodyRepository)
: space(space), bodyRepository(bodyRepository) {}

Vicinity* VicinityProvider::provideFor(Body& body) {
    Coordinates* coords = space.locate(body.id);

    if (coords != nullptr) {
        return new Vicinity(space, coords->x, coords->y, body.getId(), bodyRepository);
    } else {
        return nullptr;
    }
}
