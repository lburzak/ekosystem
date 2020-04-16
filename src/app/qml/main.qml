import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import com.polydome.ekosystem 1.0

Window {
    visible: true
    width: 800
    height: 480
    title: qsTr("Hello World")

    RowLayout {
        anchors.fill: parent

        Frame {
            Layout.fillHeight: true
            Layout.fillWidth: true

            SpaceGrid {
                anchors.centerIn: parent
            }
        }


        ColumnLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true

            OrganismsList {}

            PropertiesList {}
        }
    }
}
