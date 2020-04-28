import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import com.polydome.ekosystem 1.0

ListView {
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.maximumWidth: parent.width
        implicitHeight: 300

        clip: true

        model: OrganismPropertiesModel {
            presenter: organismPropertiesPresenter
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

            RowLayout {
                spacing: 0
                anchors.fill: parent
                Text {
                    Layout.maximumWidth: parent.width/2
                    height: parent.height
                    text: model.propertyKey
                }

                Text {
                    Layout.maximumWidth: parent.width/2
                    height: parent.height
                    text: model.propertyValue
                }
            }
        }
    }

