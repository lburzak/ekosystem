//
// Created by polydome on 4/15/20.
//

#ifndef EKOSYSTEM_ORGANISMPROPERTIESMODEL_H
#define EKOSYSTEM_ORGANISMPROPERTIESMODEL_H


#include <QtCore/QAbstractListModel>
#include "app/adapter/OrganismPropertiesPresenterAdapter.h"
#include "presentation/view/OrganismPropertiesView.h"

class OrganismPropertiesModel : public QAbstractListModel, public OrganismPropertiesView  {
    Q_OBJECT
    Q_PROPERTY(OrganismPropertiesPresenterAdapter* presenter READ presenter WRITE setPresenter)
public:
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    OrganismPropertiesPresenterAdapter* presenter() const;
    void setPresenter(OrganismPropertiesPresenterAdapter *presenter);

    void reloadList() override;

private:
    enum Role {
        PropertyKey = Qt::UserRole,
        PropertyValue
    };

    OrganismPropertiesPresenterAdapter* _presenter;

    OrganismProperty getProperty(int index) const;
};


#endif //EKOSYSTEM_ORGANISMPROPERTIESMODEL_H
