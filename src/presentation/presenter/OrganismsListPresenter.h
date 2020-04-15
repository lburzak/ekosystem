//
// Created by polydome on 4/15/20.
//

#ifndef EKOSYSTEM_ORGANISMSLISTPRESENTER_H
#define EKOSYSTEM_ORGANISMSLISTPRESENTER_H

#include <string>
#include "domain/space/space.h"
#include "presentation/state/ApplicationStore.h"

struct OrganismEntry {
    unsigned id;
    std::string type;
};

class OrganismsListPresenter {
public:
    OrganismsListPresenter(Space& space, ApplicationStore& store);

    int getSize();
    OrganismEntry entryAt(int index);

private:
    Space& space;
    ApplicationStore& store;
};


#endif //EKOSYSTEM_ORGANISMSLISTPRESENTER_H
