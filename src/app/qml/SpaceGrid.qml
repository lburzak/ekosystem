import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import com.polydome.ekosystem 1.0

Frame {
    GridView {
        implicitHeight: 500
        implicitWidth: 500
        anchors.fill: parent
        clip: true
        cellWidth: implicitHeight / 10
        cellHeight: cellWidth


        model: SpaceGridModel {
            presenter: spaceGridPresenter
        }
        delegate:
            Rectangle {
                width: 50;
                height: width;

                Rectangle {
                    anchors.centerIn: parent;
                    radius: 360
                    width: model.number * 3 < parent.width ? model.number * 3 : parent.width
                    color: "#FF8A80"
                    height: width
                    clip: true
                }

                Rectangle {
                    anchors.fill: parent
                    color: "transparent"
                    border.width: (model.selected) ? 2 : 1
                    border.color: (model.selected) ? "#1565C0" : "#d0cfd1"
                }

                Text {
                    anchors.centerIn: parent
                    font.pixelSize: 14
                    text: model.number > 0 ? model.number : ""
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: spaceGridPresenter.selectTile(index)
                }
            }
    }
}