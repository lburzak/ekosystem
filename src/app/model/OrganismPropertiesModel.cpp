//
// Created by polydome on 4/15/20.
//

#include "OrganismPropertiesModel.h"

OrganismPropertiesModel::OrganismPropertiesModel(QObject* parent) : QAbstractListModel(parent) {}

int OrganismPropertiesModel::rowCount(const QModelIndex &parent) const {
    if (presenter())
        return presenter()->getCount();
}

OrganismProperty OrganismPropertiesModel::getProperty(int index) const {
    if (index == 0) {
        return { "id", std::to_string(presenter()->getId()) };
    } else {
        return presenter()->getPropertyAt(index - 1);
    }
}

QVariant OrganismPropertiesModel::data(const QModelIndex &index, int role) const {
    if (presenter()) {

        OrganismProperty property = getProperty(index.row());

        switch (role) {
            case PropertyKey:
                return QVariant(QString::fromStdString(property.key));
            case PropertyValue:
                return QVariant(QString::fromStdString(property.value));
        }
    }

    return QVariant();
}

QHash<int, QByteArray> OrganismPropertiesModel::roleNames() const {
    QHash<int, QByteArray> names;

    names.insert(PropertyKey, "propertyKey");
    names.insert(PropertyValue, "propertyValue");

    return names;
}

OrganismPropertiesPresenterAdapter *OrganismPropertiesModel::presenter() const {
    return _presenter;
}

void OrganismPropertiesModel::setPresenter(OrganismPropertiesPresenterAdapter *presenter) {
    _presenter = presenter;
    if (_presenter)
        _presenter->attach(this);
}

void OrganismPropertiesModel::reloadList() {
    beginResetModel();
    endResetModel();
}
