//
// Created by polydome on 4/15/20.
//

#ifndef EKOSYSTEM_ORGANISMSLISTMODEL_H
#define EKOSYSTEM_ORGANISMSLISTMODEL_H


#include <QtCore/QAbstractListModel>
#include "presentation/view/OrganismsListView.h"
#include "app/adapter/OrganismsListPresenterAdapter.h"

class OrganismsListModel : public QAbstractListModel, public OrganismsListView {
    Q_OBJECT
    Q_PROPERTY(OrganismsListPresenterAdapter* presenter READ presenter WRITE setPresenter)

public:
    explicit OrganismsListModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

    OrganismsListPresenterAdapter* presenter() const;
    void setPresenter(OrganismsListPresenterAdapter* presenter);

    void reloadList() override;

private:
    OrganismsListPresenterAdapter* _presenter;

    enum Role {
        OrganismId = Qt::UserRole,
        Species
    };
};


#endif //EKOSYSTEM_ORGANISMSLISTMODEL_H
