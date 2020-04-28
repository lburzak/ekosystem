import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import com.polydome.ekosystem 1.0

RowLayout {
    spacing: 0

    Button {
        Layout.fillHeight: true
        Layout.fillWidth: true
        text: qsTr("Tick")
        onClicked: simulationControlsPresenter.tick()
    }
}
