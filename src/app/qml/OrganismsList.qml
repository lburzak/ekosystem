import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import com.polydome.ekosystem 1.0

ListView {
    Layout.fillHeight: true
    Layout.fillWidth: true
    implicitWidth: 300;
    implicitHeight: 300;

    clip: true

    model: OrganismsListModel {
        presenter: organismsListPresenter
    }

    delegate: Rectangle {
        height: 40
        width: parent.width

        Rectangle {
            height: 1
            width: parent.width
            color: "#d0cfd1"
            anchors.bottom: parent.bottom
        }

        Rectangle {
            visible: model.selected
            color: "lightgreen"
            anchors.fill: parent
        }

        Text {
            id: organismId
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: 20
            anchors.left: parent.left
            text: "ID:" + model.organismId
        }

        Text {
            id: species
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: organismId.right
            anchors.leftMargin: 20
            text: model.species
        }

        MouseArea {
            anchors.fill: parent
            onClicked: () => { organismsListPresenter.select(index) }
        }
    }
}


