//
// Created by polydome on 4/29/20.
//

#include "RandomNumberGenerator.h"
int RandomNumberGenerator::getInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}

void RandomNumberGenerator::init() {
    srand(time(nullptr));
    mt = std::mt19937(rd());
}
