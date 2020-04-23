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
    synchronizeWithState();
}

void SpaceGridPresenter::synchronizeWithState() {
    onTileSelected();
}

void SpaceGridPresenter::onTileSelected() {
    view->onTileSelectedChange(currentTile);
    currentTile = store.getState().selectedTile;
    view->onTileSelectedChange(currentTile);
}

void SpaceGridPresenter::onEvent(ApplicationEvent event) {
    switch (event) {
        case ApplicationEvent::TILE_SELECTED:
            onTileSelected();
        break;
    }
}
