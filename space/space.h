#ifndef SPACE_H
#define SPACE_H

#include "coordinates.h"

#include <body/bodyregistry.h>
#include <body/body.h>
#include <set>


class Space {
public:
    Space(BodyRegistry& bodyRegistry) : registry(bodyRegistry) {}

    void putAt(Body& body, int x, int y) {
        idsMatrix[x][y].insert(body.getId());
    }

    std::set<Body*> getBodiesAt(int x, int y) {
        std::set<unsigned> bodies = idsMatrix[x][y];
        std::set<Body*> fetchedBodies;

        for (auto it = bodies.begin(); it != bodies.end(); it++) {
            Body* fetchedBody = registry.fetch(*it);
            fetchedBodies.insert(fetchedBody);
        }

        return fetchedBodies;
    }

    Coordinates* locate(unsigned bodyId) {
        for (int x = 0; x < Space::SPACE_WIDTH; x++) {
            for (int y = 0; y < Space::SPACE_HEIGHT; y++) {
                if (idsMatrix[x][y].find(bodyId) != idsMatrix[x][y].end()) {
                    Coordinates* coords = new Coordinates();
                    coords->x = x;
                    coords->y = y;
                    return coords;
                }
            }
        }

        return nullptr;
    }

    friend class VicinityProvider;
private:
    static int const SPACE_WIDTH = 10;
    static int const SPACE_HEIGHT = 10;

    BodyRegistry& registry;
    std::set<unsigned> idsMatrix[SPACE_WIDTH][SPACE_HEIGHT];
};

#endif // SPACE_H
