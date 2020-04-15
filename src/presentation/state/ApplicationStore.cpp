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

void ApplicationStore::emitEvent(ApplicationEvent event) {
    for (auto listener : listeners) {
        listener->onEvent(event);
    }
}

ApplicationState ApplicationStore::getState() {
    return state;
}