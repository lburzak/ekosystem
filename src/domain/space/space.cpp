#include "bodynotinspaceexception.h"
#include "space.h"
#include "domain/body/body.h"
#include "iostream"

void Space::putAt(Body& body, int x, int y) {
    idsMatrix[x][y].insert(body.getId());
}

void Space::removeAt(int x, int y, int pos) {
    std::cout << "removing " << x << " " << y << " " << pos;
         auto it = idsMatrix[x][y].begin();
    for (int i = 0; it != idsMatrix[x][y].end() && i != pos; it++, i++);

    if (it != idsMatrix[x][y].end())
        idsMatrix[x][y].erase(it);
}

std::set<Body*> Space::getBodiesAt(int x, int y) {
    std::set<unsigned> bodies = idsMatrix[x][y];
    std::set<Body*> fetchedBodies;

    for (auto it = bodies.begin(); it != bodies.end(); it++) {
        Body* fetchedBody = registry.fetch(*it);
        fetchedBodies.insert(fetchedBody);
    }

    return fetchedBodies;
}

std::set<unsigned> Space::getIdsAt(int x, int y) {
    return idsMatrix[x][y];
}

Coordinates* Space::locate(unsigned bodyId) {
    for (int x = 0; x < Space::WIDTH; x++) {
        for (int y = 0; y < Space::HEIGHT; y++) {
            if (idsMatrix[x][y].find(bodyId) != idsMatrix[x][y].end()) {
                Coordinates* coords = new Coordinates();
                coords->x = x;
                coords->y = y;
                return coords;
            }
        }
    }

    throw BodyNotInSpaceException();
}

void Space::putAt(unsigned int id, int x, int y) {
    idsMatrix[x][y].insert(id);
}
