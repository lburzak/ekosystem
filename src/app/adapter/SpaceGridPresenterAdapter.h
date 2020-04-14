//
// Created by polydome on 4/14/20.
//

#ifndef EKOSYSTEM_SPACEGRIDPRESENTERADAPTER_H
#define EKOSYSTEM_SPACEGRIDPRESENTERADAPTER_H

#include "presentation/presenter/SpaceGridPresenter.h"
#include <QtCore/QObject>


class SpaceGridPresenterAdapter : public QObject {
    Q_OBJECT
public:
    SpaceGridPresenterAdapter(SpaceGridPresenter& presenter) : presenter(presenter) {}

    Q_INVOKABLE int getTilesCount() { return presenter.getTilesCount(); }
    Q_INVOKABLE unsigned getOrganismsCountAt(int index) { return presenter.getOrganismsCountAt(index); }
    Q_INVOKABLE bool isSelected(int index) { return presenter.isSelected(index); }
    Q_INVOKABLE void selectTile(int index) { presenter.selectTile(index); }
    Q_INVOKABLE void attach(SpaceGridView *view) { presenter.attach(view); };
private:
    SpaceGridPresenter& presenter;
};


#endif //EKOSYSTEM_SPACEGRIDPRESENTERADAPTER_H
