//
// Created by polydome on 4/15/20.
//

#ifndef EKOSYSTEM_ORGANISMPROPERTIESPRESENTER_H
#define EKOSYSTEM_ORGANISMPROPERTIESPRESENTER_H

#include <string>
#include "presentation/state/ApplicationStore.h"
#include "domain/space/space.h"

struct OrganismProperty {
    std::string key;
    std::string value;
};

class OrganismPropertiesPresenter {
public:
    OrganismPropertiesPresenter(ApplicationStore& store, Space& space);

    int getCount();
    OrganismProperty getPropertyAt(int index);

private:
    ApplicationStore& store;
    Space& space;
};


#endif //EKOSYSTEM_ORGANISMPROPERTIESPRESENTER_H
