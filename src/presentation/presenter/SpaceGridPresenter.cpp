//
// Created by polydome on 4/14/20.
//

#include "SpaceGridPresenter.h"
#include "domain/space/space.h"
#include "presentation/common/GridUtils.h"

int SpaceGridPresenter::getTilesCount() {
    return Space::WIDTH * Space::HEIGHT;
}

unsigned SpaceGridPresenter::getOrganismsCountAt(int index) {
    Coordinates coords = indexToCoordinates(index);
    return space.getBodiesAt(coords.x, coords.y).size();
}

bool SpaceGridPresenter::isSelected(int index) {
    return store.getState().selectedTile == index;
}

void SpaceGridPresenter::selectTile(int index) {
    store.setSelectedTile(index);
}

void SpaceGridPresenter::attach(SpaceGridView *view) {
    this->view = view;
    store.subscribe(this);
    synchronize(store.getState());
}

void SpaceGridPresenter::synchronize(ApplicationState state) {
    synchronizeCurrentTile(state);
}

void SpaceGridPresenter::synchronizeCurrentTile(ApplicationState state) {
    currentTile = state.selectedTile;
}

void SpaceGridPresenter::onEvent(ApplicationEvent event) {
    switch (event) {
        case ApplicationEvent::TILE_SELECTED:
            view->onTileSelectedChange(currentTile);
            synchronizeCurrentTile(store.getState());
            view->onTileSelectedChange(currentTile);
        break;
        case ApplicationEvent::ORGANISM_CREATED_ON_CURRENT_TILE:
            view->onOrganismsCountChange(currentTile);
    }
}
