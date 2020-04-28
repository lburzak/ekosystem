//
// Created by polydome on 4/14/20.
//

#include "SpaceGridModel.h"

int SpaceGridModel::rowCount(const QModelIndex &parent) const {
    return _presenter ? _presenter->getTilesCount() : 0;
}

QVariant SpaceGridModel::data(const QModelIndex &index, int role) const {
    if (_presenter) {
        switch (role) {
            case Number:
                return QVariant(_presenter->getOrganismsCountAt(index.row()));
            case Selected:
                return QVariant(_presenter->isSelected(index.row()));
        }
    }

    return QVariant();
}

QHash<int, QByteArray> SpaceGridModel::roleNames() const {
    QHash<int, QByteArray> names;
    names.insert(Number, "number");
    names.insert(Selected, "selected");

    return names;
}

SpaceGridPresenterAdapter *SpaceGridModel::presenter() const {
    return _presenter;
}

void SpaceGridModel::setPresenter(SpaceGridPresenterAdapter *presenter) {
    _presenter = presenter;
    _presenter->attach(this);
}

void SpaceGridModel::onTileSelectedChange(int index) {
    QModelIndex linearIndex = createIndex(index, 0);
    dataChanged(linearIndex, linearIndex, QVector<int>() << Selected);
}

void SpaceGridModel::onOrganismsCountChange(int index) {
    QModelIndex linearIndex = createIndex(index, 0);
    dataChanged(linearIndex, linearIndex, QVector<int>() << Number);
}

void SpaceGridModel::onDataChange() {
    beginResetModel();
    endResetModel();
}
