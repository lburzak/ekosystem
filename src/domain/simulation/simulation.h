#ifndef SIMULATION_H
#define SIMULATION_H

#include "entitytype.h"
#include "domain/body/bodyregistry.h"
#include "domain/space/space.h"
#include "domain/space/vicinityprovider.h"
#include "domain/organism/organism.h"
#include "domain/repository/OrganismRepository.h"

class Simulation {
public:
    Simulation(BodyRegistry& bodyRegistry, OrganismRepository& organismRepository, VicinityProvider& vicinityProvider)
        : bodyRegistry(bodyRegistry),
          organismRepository(organismRepository),
          vicinityProvider(vicinityProvider)
    {}

    void spawn(EntityType type, int x, int y);
    void tick();

private:
    BodyRegistry& bodyRegistry;
    OrganismRepository& organismRepository;
    VicinityProvider& vicinityProvider;
    std::set<Organism*> organisms;

    void cleanUp(const std::set<Organism*> &organismsInSimulation);
};

#endif // SIMULATION_H
