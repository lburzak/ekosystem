import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import com.polydome.ekosystem 1.0

Window {
    visible: true
    width: 1024
    height: 700
    title: qsTr("Hello World")

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true

            SpaceGrid {
                anchors.centerIn: parent
            }
        }

        Rectangle {
            width: 1
            color: "black"
            Layout.fillHeight: true
        }

        ColumnLayout {
            spacing: 0
            Layout.fillHeight: true
            Layout.fillWidth: true

            SimulationControlsBar {
                Layout.preferredHeight: 24
                Layout.maximumWidth: 300
            }

            Rectangle {
                height: 1
                color: "black"
                width: 300
            }

            AddOrganismBar {}

            Rectangle {
                height: 1
                color: "black"
                width: 300
            }

            OrganismsList {}

            Rectangle {
                height: 1
                color: "black"
                width: 300
            }

            PropertiesList {}
        }
    }
}
