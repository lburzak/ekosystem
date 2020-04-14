//
// Created by polydome on 4/14/20.
//

#ifndef EKOSYSTEM_SPACEGRIDPRESENTER_H
#define EKOSYSTEM_SPACEGRIDPRESENTER_H


#include "presentation/view/SpaceGridView.h"
#include "presentation/state/ApplicationStore.h"
#include "domain/space/space.h"

class SpaceGridPresenter : public ApplicationEventListener {
public:
    explicit SpaceGridPresenter(ApplicationStore& applicationStore, Space& space)
    :   store(applicationStore),
        space(space) {}

    int getTilesCount();
    unsigned getOrganismsCountAt(int index);
    bool isSelected(int index);

    void selectTile(int index);

    void attach(SpaceGridView *view);

    void onEvent(ApplicationEvent event) override;

private:
    ApplicationStore& store;
    Space& space;
    SpaceGridView* view;

    int currentTile = store.getState().selectedTile;
};


#endif //EKOSYSTEM_SPACEGRIDPRESENTER_H
