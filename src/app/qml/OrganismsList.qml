import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import com.polydome.ekosystem 1.0

ListView {

    model: OrganismsListModel {
        presenter: organismsListPresenter
    }

    delegate: RowLayout {
        height: 40

        Text {
            text: model.organismId
        }

        Text {
            text: model.species
        }
    }
}


