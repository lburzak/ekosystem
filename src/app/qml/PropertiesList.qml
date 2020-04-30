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
                height: parent.height - 1
                width: parent.width
                Rectangle {
                    width: parent.width / 2
                    height: parent.height

                    Text {
                        x: 12
                        anchors.verticalCenter: parent.verticalCenter
                        text: model.propertyKey
                    }
                }

                Rectangle {
                    height: parent.height
                    width: 1
                    color: "#d0cfd1"
                }

                Rectangle {
                    width: parent.width / 2
                    height: parent.height

                    Text {
                        x: 12
                        anchors.verticalCenter: parent.verticalCenter
                        text: model.propertyValue
                    }
                }
            }
        }
    }

