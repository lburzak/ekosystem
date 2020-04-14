#ifndef SPACE_H
#define SPACE_H

#include "coordinates.h"

#include "domain/body/body.h"
#include "domain/body/bodyregistry.h"
#include <set>


class Space {
    friend class VicinityProvider;

public:
    Space(BodyRegistry& bodyRegistry) : registry(bodyRegistry) {}
    void putAt(Body& body, int x, int y);
    std::set<Body*> getBodiesAt(int x, int y);
    Coordinates* locate(unsigned bodyId);

private:
    static int const SPACE_WIDTH = 10;
    static int const SPACE_HEIGHT = 10;

    BodyRegistry& registry;
    std::set<unsigned> idsMatrix[SPACE_WIDTH][SPACE_HEIGHT];
};

#endif // SPACE_H
