//
// Created by polydome on 4/14/20.
//

#ifndef EKOSYSTEM_APPLICATIONSTORE_H
#define EKOSYSTEM_APPLICATIONSTORE_H


#include "ApplicationEventListener.h"
#include "ApplicationState.h"
#include <set>

class ApplicationStore {
public:
    void subscribe(ApplicationEventListener* listener);
    ApplicationState getState();
    void setSelectedTile(int index);
    void setSelectedOrganism(int index);
    void notifyOrganismCreated();

private:
    ApplicationState state;

    std::set<ApplicationEventListener*> listeners;
    void emitEvent(ApplicationEvent event);
};


#endif //EKOSYSTEM_APPLICATIONSTORE_H
