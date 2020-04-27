//
// Created by polydome on 4/25/20.
//

#ifndef EKOSYSTEM_ADDORGANISMPRESENTERADAPTER_H
#define EKOSYSTEM_ADDORGANISMPRESENTERADAPTER_H

#include "presentation/presenter/AddOrganismPresenter.h"
#include <QtCore/QObject>

class AddOrganismPresenterAdapter : public QObject {
    Q_OBJECT
public:
    explicit AddOrganismPresenterAdapter(AddOrganismPresenter& presenter) : presenter(presenter) {}

    string getOptionAt(int position) { return presenter.getOptionAt(position); }
    int getOptionsCount() { return presenter.getOptionsCount(); }
    Q_INVOKABLE void addSelectedOrganism(int position) { presenter.addSelectedOrganism(position); }

private:
    AddOrganismPresenter& presenter;
};

#endif //EKOSYSTEM_ADDORGANISMPRESENTERADAPTER_H
