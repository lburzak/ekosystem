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
    Coordinates coords = indexToCoordinates(store.getState().selectedTile);
    std::set<Body*> bodies = space.getBodiesAt(coords.x, coords.y);

    auto it = bodies.begin();
    for (int i = 0; i < index; i++)
        if (it == bodies.end())
            return defaultEntry();
        else
            it++;

    if (auto* organism = dynamic_cast<Organism*>((*it)))
        return { organism->getId(), organism->bundleInfo().get(Organism::BUNDLE_LABEL_SPECIES) };
    else
        return defaultEntry();
}
