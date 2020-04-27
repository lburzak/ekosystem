//
// Created by polydome on 4/14/20.
//

#include "ApplicationStore.h"

void ApplicationStore::subscribe(ApplicationEventListener *listener) {
    listeners.insert(listener);
}

void ApplicationStore::setSelectedTile(int index) {
    state.selectedTile = index;
    emitEvent(TILE_SELECTED);
}

void ApplicationStore::setSelectedOrganism(int index) {
    state.selectedOrganism = index;
    emitEvent(ORGANISM_SELECTED);
}

void ApplicationStore::emitEvent(ApplicationEvent event) {
    for (auto listener : listeners) {
        listener->onEvent(event);
    }
}

ApplicationState ApplicationStore::getState() {
    return state;
}

void ApplicationStore::notifyOrganismCreated() {
    emitEvent(ORGANISM_CREATED_ON_CURRENT_TILE);
}
