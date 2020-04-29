//
// Created by polydome on 4/29/20.
//

#include "spawn.h"
#include "domain/organism/human.h"
#include "domain/organism/virus.h"
#include "domain/repository/BodyRepository.h"

void spawn(OrganismType type, BodyRepository& organismRepository, int x, int y) {
    Organism* organism;
    switch (type) {
        case OrganismType::HUMAN:{
            organism = new Human();
            break;
        }
        case OrganismType::VIRUS:{
            organism = new Virus();
            break;
        }
        default:
            cerr << "NO SUCH ENTITY TYPE: " << type << endl;
            return;
    }

    organismRepository.insert(*organism, x, y);
}