import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import com.polydome.ekosystem 1.0

RowLayout {
    Layout.preferredHeight: 24
    Layout.maximumWidth: 300
    Layout.alignment: Qt.AlignCenter

    ComboBox {
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.preferredWidth: 4

        id: comboBox

        textRole: "option"
        model: AddOrganismBarModel {
            presenter: addOrganismPresenter
        }
    }

    Button {
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.preferredWidth: 1
        Layout.alignment: Qt.AlignRight
        text: qsTr("Add")
        onClicked: addOrganismPresenter.addSelectedOrganism(comboBox.currentIndex)
    }
}