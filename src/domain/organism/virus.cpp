#include "virus.h"
#include "string"


void Virus::onTick(Vicinity vicinity) {
    if (victim == nullptr) attemptAttack(vicinity.getBodies());
    if (victim == nullptr) die();
}

void Virus::attack(Human *human) {
    victim = human;
}

void Virus::attemptAttack(set<Body*> availableBodies) {
    for (auto it = availableBodies.begin(); it != availableBodies.end(); it++) {
        if (Human* human = dynamic_cast<Human*>(*it)) {
            attack(human);
            break;
        }
    }
}

InfoBundle Virus::bundleInfo() {
    InfoBundle bundle = Organism::bundleInfo();
    bundle.set("hasVictim", to_string(victim != nullptr));
    return bundle;
}
