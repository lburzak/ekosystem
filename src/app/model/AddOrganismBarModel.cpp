//
// Created by polydome on 4/25/20.
//

#include "AddOrganismBarModel.h"
#include <QDebug>

int AddOrganismBarModel::rowCount(const QModelIndex &parent) const {
    return presenter()->getOptionsCount();
}

QVariant AddOrganismBarModel::data(const QModelIndex &index, int role) const {
    if (presenter()) {
        return QVariant(QString::fromStdString(presenter()->getOptionAt(index.row())));
    }
    return QVariant();
}

AddOrganismPresenterAdapter *AddOrganismBarModel::presenter() const {
    return _presenter;
}

void AddOrganismBarModel::setPresenter(AddOrganismPresenterAdapter *presenter) {
    _presenter = presenter;
}

QHash<int, QByteArray> AddOrganismBarModel::roleNames() const {
    QHash<int, QByteArray> names;

    names.insert(Qt::UserRole, "option");

    return names;
}
