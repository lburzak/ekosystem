#ifndef SIMULATION_H
#define SIMULATION_H

#include "entitytype.h"
#include "domain/body/bodyregistry.h"
#include "domain/space/space.h"
#include "domain/space/vicinityprovider.h"
#include "domain/organism/organism.h"


class Simulation {
public:
    Simulation(BodyRegistry& bodyRegistry, Space& space, VicinityProvider& vicinityProvider)
        : bodyRegistry(bodyRegistry),
          space(space),
          vicinityProvider(vicinityProvider)
    {}

    void spawn(EntityType type, int x, int y);
    void tick();

private:
    BodyRegistry& bodyRegistry;
    Space& space;
    VicinityProvider& vicinityProvider;
    std::set<Organism*> organisms;

    void addOrganism(Organism* organism, int x, int y);
    void cleanUp();
};

#endif // SIMULATION_H
