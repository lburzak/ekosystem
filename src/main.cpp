#include <iostream>
#include "domain/body/bodyregistry.h"
#include "domain/space/space.h"
#include "domain/simulation/simulation.h"
#include "presentation/presenter/OrganismsListPresenter.h"
#include "presentation/presenter/OrganismPropertiesPresenter.h"
#include "presentation/presenter/AddOrganismPresenter.h"
#include "app/QtApplication.h"

using namespace std;

int main(int argc, char *argv[]) {
    BodyRegistry bodyRegistry;
    Space space(bodyRegistry);
    VicinityProvider vicinityProvider(space);
    Simulation simulation(bodyRegistry, space, vicinityProvider);

    simulation.spawn(EntityType::HUMAN, 1, 2);
    simulation.spawn(EntityType::VIRUS, 1, 1);
    simulation.spawn(EntityType::VIRUS, 1, 1);
    simulation.spawn(EntityType::VIRUS, 1, 1);
    simulation.spawn(EntityType::VIRUS, 1, 1);
    simulation.spawn(EntityType::VIRUS, 1, 1);

    ApplicationStore applicationStore;
    SpaceGridPresenter spaceGridPresenter(applicationStore, space);
    OrganismsListPresenter organismsListPresenter(space, applicationStore);
    OrganismPropertiesPresenter organismPropertiesPresenter(applicationStore, space);
    AddOrganismPresenter addOrganismPresenter(simulation, applicationStore);

    return QtApplication::run(argc, argv, spaceGridPresenter, organismsListPresenter, organismPropertiesPresenter,
                              addOrganismPresenter);
}
