import QtQuick 2.0
import QtQuick.Layouts 1.12

RowLayout{
    id: loGenerar
    property int topSpace: 250
    anchors.fill: parent
    Item {
        Layout.fillWidth: true
    }

    ColumnLayout{
        Layout.bottomMargin: topSpace
        Text {
            Layout.alignment: Qt.AlignHCenter
            id: text_score
            text: qsTr("SCORE:")
            font.pixelSize: 30
            font.bold: true
        }
        Rectangle{
            id: scoar
            width: 150
            height: width
            border.width: 2
        }
    }
    Item {
        Layout.fillWidth: true
    }

    Grid{
        id: main_grid
        Layout.alignment: Qt.AlignHCenter
        rows: 20
        columns: 10
        Repeater{
            model: main_grid.rows * main_grid.columns
            Rectangle{
                width: 25
                height: width
                border.width: 1
            }
        }
    }
    Item {
        Layout.fillWidth: true
    }

    ColumnLayout{
        Layout.bottomMargin: topSpace
        Text {
            id: text_next
            Layout.alignment: Qt.AlignHCenter
            text: qsTr("NEXT:")
            font.pixelSize: 30
            font.bold: true
        }
        Rectangle{
            id: next_figure
            width: 150
            height: width
            border.width: 2
        }

    }
    Item {
        Layout.fillWidth: true
    }

}







