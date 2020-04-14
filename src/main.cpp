#include <iostream>
#include "domain/body/bodyregistry.h"
#include "domain/space/space.h"
#include "domain/simulation/simulation.h"

using namespace std;


int main() {
    BodyRegistry bodyRegistry;
    Space space(bodyRegistry);
    VicinityProvider vicinityProvider(space);
    Simulation simulation(bodyRegistry, space, vicinityProvider);

    simulation.spawn(EntityType::HUMAN, 1, 2);
    simulation.spawn(EntityType::VIRUS, 1, 1);

    for (int i = 0; i <= 5; i++) {
        simulation.tick();
    }

    cout << "Hello World!" << endl;
    return 0;
}
