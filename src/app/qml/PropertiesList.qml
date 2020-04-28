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

        model: OrganismPropertiesModel {
            presenter: organismPropertiesPresenter
        }

        delegate: Rectangle {
            height: 40
            width: parent.width

            RowLayout {
                spacing: 5
                Text {
                    Layout.alignment: Qt.AlignVCenter
                    width: parent.width / 2
                    text: model.propertyKey
                }

                TextField {
                    Layout.alignment: Qt.AlignRight
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    text: model.propertyValue
                }
            }
        }
    }

