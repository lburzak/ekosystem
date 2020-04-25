//
// Created by polydome on 4/25/20.
//

#ifndef EKOSYSTEM_ADDORGANISMPRESENTER_H
#define EKOSYSTEM_ADDORGANISMPRESENTER_H


#include <set>
#include <string>
#include "presentation/view/AddOrgainsmView.h"
#include "domain/simulation/simulation.h"
#include "presentation/state/ApplicationStore.h"

class AddOrganismPresenter {
public:
    AddOrganismPresenter(Simulation &simulation, ApplicationStore &store);

    string getOptionAt(int position);
    int getOptionsCount();
    void addSelectedOrganism();

    void attach(AddOrganismView* view);
private:
    AddOrganismView* view = nullptr;
    Simulation& simulation;
    ApplicationStore& store;
};


#endif //EKOSYSTEM_ADDORGANISMPRESENTER_H
