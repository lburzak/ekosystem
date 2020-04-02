#include "human.h"


void Human::eat() { cout << "eating!" << endl; }

void Human::onTick(Vicinity vicinity) {
    cout << "human tick" << endl;
}
