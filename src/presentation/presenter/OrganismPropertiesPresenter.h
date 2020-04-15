//
// Created by polydome on 4/15/20.
//

#ifndef EKOSYSTEM_ORGANISMPROPERTIESPRESENTER_H
#define EKOSYSTEM_ORGANISMPROPERTIESPRESENTER_H

#include <string>
#include "presentation/state/ApplicationStore.h"
#include "presentation/state/ApplicationEventListener.h"
#include "domain/space/space.h"
#include "presentation/view/OrganismPropertiesView.h"

struct OrganismProperty {
    std::string key;
    std::string value;
};

class OrganismPropertiesPresenter : public ApplicationEventListener {
public:
    OrganismPropertiesPresenter(ApplicationStore& store, Space& space);

    int getCount();
    OrganismProperty getPropertyAt(int index);

    void attach(OrganismPropertiesView *view);

    void onEvent(ApplicationEvent event) override;

private:
    ApplicationStore& store;
    Space& space;
    OrganismPropertiesView* view;
};


#endif //EKOSYSTEM_ORGANISMPROPERTIESPRESENTER_H
