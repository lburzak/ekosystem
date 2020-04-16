//
// Created by polydome on 4/15/20.
//

#include "OrganismPropertiesPresenter.h"
#include "presentation/common/GridUtils.h"

OrganismProperty noProperty() {
    return { "INVALID_PROPERTY", "NO_SUCH_PROPERTY" };
}

OrganismPropertiesPresenter::OrganismPropertiesPresenter(ApplicationStore &store, Space &space)
    : store(store), space(space) {}

int OrganismPropertiesPresenter::getCount() {
    Organism* organism = fetchOrganismAt(space, store.getState().selectedTile, store.getState().selectedOrganism);

    if (!organism)
        return 0;

    InfoBundle bundle = organism->bundleInfo();

    return bundle.keys().size();
}

OrganismProperty OrganismPropertiesPresenter::getPropertyAt(int index) {
    Organism* organism = fetchOrganismAt(space, store.getState().selectedTile, store.getState().selectedOrganism);

    if (!organism)
        return noProperty();

    InfoBundle bundle = organism->bundleInfo();

    std::set<string> keys = bundle.keys();
    auto it = keys.begin();
    for (int i = 0; i < index; i++) {
        if (it == keys.end())
            return noProperty();
        else
            it++;
    }

    return { *it, bundle.get(*it) };
}

unsigned OrganismPropertiesPresenter::getId() {
    Organism* organism = fetchOrganismAt(space, store.getState().selectedTile, store.getState().selectedOrganism);

    if (organism)
        return organism->getId();

    return 0;
}

void OrganismPropertiesPresenter::attach(OrganismPropertiesView *view) {
    this->view = view;
    store.subscribe(this);
}

void OrganismPropertiesPresenter::onEvent(ApplicationEvent event) {
    switch (event) {
        case ORGANISM_SELECTED:
            if (view) view->reloadList();
    }
}

bool OrganismPropertiesPresenter::hasSelectedOrganism() {
    return store.getState().selectedOrganism != SELECTED_ORGANISM_NO_ORGANISM;
}
