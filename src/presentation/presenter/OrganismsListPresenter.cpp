//
// Created by polydome on 4/15/20.
//

#include "OrganismsListPresenter.h"
#include "presentation/common/GridUtils.h"
#include "domain/organism/organism.h"

OrganismEntry defaultEntry() {
    return { 0, "NO_SUCH_ORGANISM" };
}

bool isAnyTileSelected(ApplicationState state) {
    return state.selectedTile != -1;
}

OrganismsListPresenter::OrganismsListPresenter(Space &space, ApplicationStore &store)
        : space(space), store(store) {}

int OrganismsListPresenter::getSize() {
    if (isAnyTileSelected(store.getState())) {
        Coordinates coords = indexToCoordinates(store.getState().selectedTile);
        return space.getBodiesAt(coords.x, coords.y).size();
    } else {
        return 0;
    }
}

OrganismEntry OrganismsListPresenter::entryAt(int index) {
    Organism* organism = fetchOrganismAt(space, store.getState().selectedTile, index);

    if (organism)
        return { organism->getId(), organism->bundleInfo().get(Organism::BUNDLE_LABEL_SPECIES) };
    else
        return defaultEntry();
}

void OrganismsListPresenter::attach(OrganismsListView *view) {
    this->view = view;
    store.subscribe(this);
    synchronize(store.getState());
}

void OrganismsListPresenter::synchronizeSelectedOrganism(ApplicationState state) {
    currentOrganism = state.selectedOrganism;
}

void OrganismsListPresenter::synchronize(ApplicationState state) {
    synchronizeSelectedOrganism(state);
}

void OrganismsListPresenter::onEvent(ApplicationEvent event) {
    switch (event) {
        case TILE_SELECTED:
            if (view)
                view->reloadList();
        break;
        case ORGANISM_SELECTED:
            if (view)
                view->onOrganismSelectedChange(currentOrganism);
                synchronizeSelectedOrganism(store.getState());
                view->onOrganismSelectedChange(currentOrganism);
        break;
    }
}

bool OrganismsListPresenter::isSelected(int index) {
    return store.getState().selectedOrganism == index;
}

void OrganismsListPresenter::select(int index) {
    store.setSelectedOrganism(index);
}
