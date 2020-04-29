#include "human.h"


void Human::eat() { cout << "eating!" << endl; }

void Human::onTick(Vicinity vicinity) {
    if (coughCooldown == 0) {
        vicinity.applyForce(10);
        coughCooldown = COUGH_COOLDOWN_BASE;
    } else {
        coughCooldown--;
    }
}

string Human::getVisibleName() {
    return "Human";
}
