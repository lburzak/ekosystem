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

    static int const WIDTH = 10;
    static int const HEIGHT = 10;
private:

    BodyRegistry& registry;
    std::set<unsigned> idsMatrix[WIDTH][HEIGHT];
};

#endif // SPACE_H
