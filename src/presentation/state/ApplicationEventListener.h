//
// Created by polydome on 4/14/20.
//

#ifndef EKOSYSTEM_APPLICATIONEVENTLISTENER_H
#define EKOSYSTEM_APPLICATIONEVENTLISTENER_H

#include "ApplicationEvent.h"

class ApplicationEventListener {
public:
    virtual void onEvent(ApplicationEvent event) = 0;
};

#endif //EKOSYSTEM_APPLICATIONEVENTLISTENER_H
