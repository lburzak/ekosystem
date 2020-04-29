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
    void removeById(unsigned id);
    void insert(Body& body, int x, int y);
private:
    Space& space;
    BodyRegistry& registry;
};


#endif //EKOSYSTEM_BODYREPOSITORY_H
