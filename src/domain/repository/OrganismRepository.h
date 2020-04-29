//
// Created by polydome on 4/29/20.
//

#ifndef EKOSYSTEM_ORGANISMREPOSITORY_H
#define EKOSYSTEM_ORGANISMREPOSITORY_H

#include <set>
#include "domain/organism/organism.h"
#include "domain/body/bodyregistry.h"


class OrganismRepository {
public:
    OrganismRepository(Space& space, BodyRegistry& bodyRegistry);

    std::set<Organism*> getAll();
    void removeById(unsigned id);
    void insert(Organism& organism, int x, int y);
private:
    Space& space;
    BodyRegistry& registry;
};


#endif //EKOSYSTEM_ORGANISMREPOSITORY_H
