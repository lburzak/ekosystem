#include <iostream>
#include "domain/body/bodyregistry.h"
#include "domain/space/space.h"
#include "domain/simulation/simulation.h"
#include "presentation/presenter/OrganismsListPresenter.h"
#include "presentation/presenter/OrganismPropertiesPresenter.h"
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

    applicationStore.setSelectedTile(11);
    applicationStore.setSelectedOrganism(0);

    cout << organismPropertiesPresenter.getCount() << endl;

    for (int i = 0; i < organismPropertiesPresenter.getCount(); i++) {
        auto prop = organismPropertiesPresenter.getPropertyAt(i);
        cout << prop.key << " => " << prop.value << endl;
    }

//    for (int i = 0; i <= 5; i++) {
//        simulation.tick();
//    }


//    cout << "Hello World!" << endl;
    return QtApplication::run(argc, argv, spaceGridPresenter, organismsListPresenter, organismPropertiesPresenter);
}
