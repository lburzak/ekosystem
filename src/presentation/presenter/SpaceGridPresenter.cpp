//
// Created by polydome on 4/14/20.
//

#include "SpaceGridPresenter.h"
#include "domain/space/space.h"

Coordinates indexToCoordinates(int index) {
    return { index % Space::WIDTH, index / Space::WIDTH };
}

unsigned SpaceGridPresenter::getTilesCount() {
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
}

void SpaceGridPresenter::onEvent(ApplicationEvent event) {
    switch (event) {
        case ApplicationEvent::TILE_SELECTED:
            view->onTileChange(currentTile);
            currentTile = store.getState().selectedTile;
            view->onTileChange(currentTile);
        break;
    }
}
