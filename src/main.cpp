#include "domain/body/bodyregistry.h"
#include "domain/space/space.h"
#include "domain/simulation/simulation.h"
#include "domain/repository/BodyRepository.h"
#include "presentation/presenter/OrganismsListPresenter.h"
#include "presentation/presenter/OrganismPropertiesPresenter.h"
#include "presentation/presenter/AddOrganismPresenter.h"
#include "app/QtApplication.h"

using namespace std;

int runQtApplication(int argc, char* argv[], Space& space, Simulation& simulation);

int main(int argc, char *argv[]) {
    BodyRegistry bodyRegistry;
    Space space(bodyRegistry);
    BodyRepository organismRepository(space, bodyRegistry);
    VicinityProvider vicinityProvider(space, organismRepository);

    Simulation simulation(bodyRegistry, organismRepository, vicinityProvider);

    return runQtApplication(argc, argv, space, simulation);
}

int runQtApplication(const int argc, char* argv[], Space& space, Simulation& simulation) {
    ApplicationStore applicationStore;
    SpaceGridPresenter spaceGridPresenter(applicationStore, space);
    OrganismsListPresenter organismsListPresenter(space, applicationStore);
    OrganismPropertiesPresenter organismPropertiesPresenter(applicationStore, space);
    AddOrganismPresenter addOrganismPresenter(simulation, applicationStore);
    SimulationControlsPresenter simulationControlsPresenter(simulation, applicationStore);

    return QtApplication::run(argc, argv, spaceGridPresenter, organismsListPresenter, organismPropertiesPresenter,
                              addOrganismPresenter, simulationControlsPresenter);
}
