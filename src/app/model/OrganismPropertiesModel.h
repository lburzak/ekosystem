//
// Created by polydome on 4/15/20.
//

#ifndef EKOSYSTEM_ORGANISMPROPERTIESMODEL_H
#define EKOSYSTEM_ORGANISMPROPERTIESMODEL_H


#include <QtCore/QAbstractListModel>
#include "app/adapter/OrganismPropertiesPresenterAdapter.h"

class OrganismPropertiesModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(OrganismPropertiesPresenterAdapter* presenter READ presenter WRITE setPresenter)
public:
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    OrganismPropertiesPresenterAdapter* presenter() const;
    void setPresenter(OrganismPropertiesPresenterAdapter *presenter);

private:
    enum Role {
        PropertyKey = Qt::UserRole,
        PropertyValue
    };

    OrganismPropertiesPresenterAdapter* _presenter;
};


#endif //EKOSYSTEM_ORGANISMPROPERTIESMODEL_H
