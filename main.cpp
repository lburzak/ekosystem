#include <iostream>
#include <set>
#include <map>
#include <space/vicinity.h>
#include <space/vicinityprovider.h>
#include <simulation/simulation.h>
#include "body/body.h"
#include "body/bodyregistry.h"
#include "space/space.h"

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
