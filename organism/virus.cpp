#include "virus.h"


void Virus::onTick(Vicinity vicinity) {
    set<Body*> bodies = vicinity.getBodies();
    for (auto it = bodies.begin(); it != bodies.end(); it++) {
        if (Human* human = dynamic_cast<Human*>(*it)) {
            attack(human);
            human->eat();
        }
    }
}

void Virus::attack(Human *human) {
    victim = human;
}
