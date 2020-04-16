//
// Created by polydome on 4/14/20.
//

#ifndef EKOSYSTEM_APPLICATIONSTATE_H
#define EKOSYSTEM_APPLICATIONSTATE_H

static int SELECTED_ORGANISM_NO_ORGANISM = -1;

struct ApplicationState {
    int selectedTile = -1;
    int selectedOrganism = SELECTED_ORGANISM_NO_ORGANISM;
};


#endif //EKOSYSTEM_APPLICATIONSTATE_H
