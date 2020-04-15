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

        model: OrganismPropertiesModel {
            presenter: organismPropertiesPresenter
        }

        delegate: Frame {
            height: 40
            width: parent.width

            RowLayout {
                Text {
                    text: model.propertyKey
                }

                Text {
                    text: model.propertyValue
                }
            }
        }
    }
}


