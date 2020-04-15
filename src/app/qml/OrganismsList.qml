import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import com.polydome.ekosystem 1.0

Frame {
    Layout.fillHeight: true
    ListView {
        implicitWidth: 300;
        implicitHeight: 300;

        model: OrganismsListModel {
            presenter: organismsListPresenter
        }

        delegate: Frame {
            height: 40
            width: parent.width
            Rectangle {
                visible: model.selected
                color: "green"
                anchors.fill: parent
            }

            RowLayout {
                Text {
                    text: model.organismId
                }

                Text {
                    text: model.species
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: () => { organismsListPresenter.select(index) }
            }
        }
    }
}


