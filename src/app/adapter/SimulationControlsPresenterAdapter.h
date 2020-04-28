//
// Created by polydome on 4/28/20.
//

#ifndef EKOSYSTEM_SIMULATIONCONTROLSPRESENTERADAPTER_H
#define EKOSYSTEM_SIMULATIONCONTROLSPRESENTERADAPTER_H

#include <QtCore/QObject>
#include "presentation/presenter/SimulationControlsPresenter.h"

class SimulationControlsPresenterAdapter : public QObject {
    Q_OBJECT
public:
    explicit SimulationControlsPresenterAdapter(SimulationControlsPresenter& presenter) : presenter(presenter) {}

    Q_INVOKABLE void tick() { presenter.tick(); }

private:
    SimulationControlsPresenter& presenter;
};

#endif //EKOSYSTEM_SIMULATIONCONTROLSPRESENTERADAPTER_H
