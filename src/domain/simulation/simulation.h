#ifndef SIMULATION_H
#define SIMULATION_H

#include "domain/organism/OrganismType.h"
#include "domain/body/bodyregistry.h"
#include "domain/space/space.h"
#include "domain/space/vicinityprovider.h"
#include "domain/organism/organism.h"
#include "domain/repository/BodyRepository.h"

class Simulation {
public:
    Simulation(BodyRegistry& bodyRegistry, BodyRepository& bodyRepository, VicinityProvider& vicinityProvider)
        : bodyRegistry(bodyRegistry),
          bodyRepository(bodyRepository),
          vicinityProvider(vicinityProvider)
    {}

    void spawnEntity(OrganismType type, int x, int y);
    void tick();

private:
    BodyRegistry& bodyRegistry;
    BodyRepository& bodyRepository;
    VicinityProvider& vicinityProvider;
    std::set<Organism*> organisms;

    void cleanUp(const std::set<Organism*> &organismsInSimulation);
};

#endif // SIMULATION_H
