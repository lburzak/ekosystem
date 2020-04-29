#include "human.h"


void Human::eat() { cout << "eating!" << endl; }

void Human::onTick(Vicinity vicinity) {
    vicinity.applyForce(10);
}

string Human::getVisibleName() {
    return "Human";
}
