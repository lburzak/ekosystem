//
// Created by polydome on 4/29/20.
//

#ifndef EKOSYSTEM_BODYREPOSITORY_H
#define EKOSYSTEM_BODYREPOSITORY_H

#include "domain/space/space.h"
#include "domain/body/bodyregistry.h"

class BodyRepository {
public:
    BodyRepository(Space& space, BodyRegistry& bodyRegistry);

    std::set<Body*> getAll();
    std::set<Body*> getAt(int x, int y);
    void removeById(unsigned id);
    void move(unsigned id, int targetX, int targetY);
    void insert(Body& body, int x, int y);
    int countAt(int x, int y);
private:
    struct FindByIdResult {
        unsigned id;
        int position;
        bool found;
        Coordinates coordinates;
    };

    FindByIdResult findById(unsigned id);
    Space& space;
    BodyRegistry& registry;
};


#endif //EKOSYSTEM_BODYREPOSITORY_H
