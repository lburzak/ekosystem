//
// Created by polydome on 4/14/20.
//

#ifndef EKOSYSTEM_QTAPPLICATION_H
#define EKOSYSTEM_QTAPPLICATION_H

#include "presentation/state/ApplicationStore.h"
#include "presentation/presenter/SpaceGridPresenter.h"

class QtApplication {
public:
    static int run(int argc, char **argv, SpaceGridPresenter &spaceGridPresenter,
                   OrganismsListPresenter &organismsListPresenter,
                   OrganismPropertiesPresenter &organismPropertiesPresenter);
};


#endif //EKOSYSTEM_QTAPPLICATION_H
