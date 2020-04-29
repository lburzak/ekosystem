#include "virus.h"
#include "string"


void Virus::onTick(Vicinity vicinity) {
    victim = nullptr;
    attemptAttack(vicinity.getBodies());
    if (victim == nullptr) die();
    if (victim) {
        vicinity.spawnNear(OrganismType::VIRUS);
    }
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

string Virus::getVisibleName() {
    return "Virus";
}

InfoBundle Virus::bundleInfo() {
    InfoBundle bundle = Organism::bundleInfo();
    bundle.set("hasVictim", to_string(victim != nullptr));
    return bundle;
}
