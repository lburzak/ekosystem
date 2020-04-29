//
// Created by polydome on 4/29/20.
//

#ifndef EKOSYSTEM_RANDOMNUMBERGENERATOR_H
#define EKOSYSTEM_RANDOMNUMBERGENERATOR_H

#include <random>

class RandomNumberGenerator {
public:
    void init();
    int getInt(int min, int max);

private:
    std::random_device rd;
    std::mt19937 mt;
};


#endif //EKOSYSTEM_RANDOMNUMBERGENERATOR_H
