//
// Created by polydome on 4/15/20.
//

#include "OrganismsListModel.h"
#include <QDebug>

OrganismsListModel::OrganismsListModel(QObject *parent)
    : QAbstractListModel(parent) {}

int OrganismsListModel::rowCount(const QModelIndex &parent) const {
    return _presenter->getSize();
}

QVariant OrganismsListModel::data(const QModelIndex &index, int role) const {
    if (_presenter) {
        OrganismEntry entry = _presenter->entryAt(index.row());

        switch (role) {
            case OrganismId:
                return QVariant(entry.id);
            case Species:
                return QVariant(QString::fromStdString(entry.type));
            case Selected:
                return QVariant(_presenter->isSelected(index.row()));
        }
    }

    return QVariant();
}

QHash<int, QByteArray> OrganismsListModel::roleNames() const {
    QHash<int, QByteArray> names;

    names.insert(OrganismId, "organismId");
    names.insert(Species, "species");
    names.insert(Selected, "selected");

    return names;
}

OrganismsListPresenterAdapter *OrganismsListModel::presenter() const {
    return _presenter;
}

void OrganismsListModel::setPresenter(OrganismsListPresenterAdapter *presenter) {
    _presenter = presenter;
    _presenter->attach(this);
}

void OrganismsListModel::reloadList() {
    beginResetModel();
    endResetModel();
}

void OrganismsListModel::onOrganismSelectedChange(int index) {
    QModelIndex linearIndex = createIndex(index, 0);
    dataChanged(linearIndex, linearIndex, QVector<int>() << Selected);
}
