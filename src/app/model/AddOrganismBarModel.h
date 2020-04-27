//
// Created by polydome on 4/25/20.
//

#ifndef EKOSYSTEM_ADDORGANISMBARMODEL_H
#define EKOSYSTEM_ADDORGANISMBARMODEL_H


#include "app/adapter/AddOrganismPresenterAdapter.h"
#include <QtCore/QAbstractListModel>

class AddOrganismBarModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(AddOrganismPresenterAdapter* presenter READ presenter WRITE setPresenter)
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    AddOrganismPresenterAdapter* presenter() const;
    void setPresenter(AddOrganismPresenterAdapter* presenter);

    QHash<int, QByteArray> roleNames() const override;

private:
    AddOrganismPresenterAdapter* _presenter;
};


#endif //EKOSYSTEM_ADDORGANISMBARMODEL_H
