import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

RowLayout {
    Layout.preferredHeight: 24
    Layout.maximumWidth: 300
    Layout.alignment: Qt.AlignCenter

    ComboBox {
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.preferredWidth: 4
        model: [ "Banana", "Apple", "Coconut" ]
    }

    Button {
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.preferredWidth: 1
        Layout.alignment: Qt.AlignRight
        text: qsTr("Add")
    }
}