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
    InfoBundle bundle =
        fetchOrganismAt(space, store.getState().selectedTile, store.getState().selectedOrganism)->bundleInfo();

    return bundle.keys().size();
}

OrganismProperty OrganismPropertiesPresenter::getPropertyAt(int index) {
    InfoBundle bundle =
            fetchOrganismAt(space, store.getState().selectedTile, store.getState().selectedOrganism)->bundleInfo();

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
