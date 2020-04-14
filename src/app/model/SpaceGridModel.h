//
// Created by polydome on 4/14/20.
//

#ifndef EKOSYSTEM_SPACEGRIDMODEL_H
#define EKOSYSTEM_SPACEGRIDMODEL_H


#include <QtCore/QAbstractListModel>
#include "app/adapter/SpaceGridPresenterAdapter.h"
#include "presentation/view/SpaceGridView.h"

class SpaceGridModel : public QAbstractListModel, public SpaceGridView {
    Q_OBJECT
    Q_PROPERTY(SpaceGridPresenterAdapter* presenter READ presenter WRITE setPresenter)
public:
    void onTileSelectedChange(int index) override;

    int rowCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

    SpaceGridPresenterAdapter* presenter() const;;
    void setPresenter(SpaceGridPresenterAdapter* presenter);

private:
    enum Role {
        Selected = Qt::UserRole,
        Number
    };

    SpaceGridPresenterAdapter* _presenter;
};


#endif //EKOSYSTEM_SPACEGRIDMODEL_H
