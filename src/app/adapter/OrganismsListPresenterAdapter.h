//
// Created by polydome on 4/15/20.
//

#ifndef EKOSYSTEM_ORGANISMSLISTPRESENTERADAPTER_H
#define EKOSYSTEM_ORGANISMSLISTPRESENTERADAPTER_H

#include "presentation/presenter/OrganismsListPresenter.h"
#include "presentation/view/OrganismsListView.h"
#include <QtCore/QObject>

class OrganismsListPresenterAdapter : public QObject {
    Q_OBJECT
public:
    OrganismsListPresenterAdapter(OrganismsListPresenter& presenter) : presenter(presenter) {};

    Q_INVOKABLE int getSize() { return presenter.getSize(); }
    Q_INVOKABLE OrganismEntry entryAt(int index) { return presenter.entryAt(index); }
    void attach(OrganismsListView* view) { presenter.attach(view); }
private:
    OrganismsListPresenter& presenter;
};

#endif //EKOSYSTEM_ORGANISMSLISTPRESENTERADAPTER_H
