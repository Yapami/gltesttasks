import QtQuick 2.0
import QtQuick.Layouts 1.12

RowLayout{
    id: loGenerar
    property int top_space: 250
    property int rect_size: 150
    anchors.fill: parent

    ColumnLayout{
        id: scoar
        Layout.bottomMargin: top_space
        anchors.right: main_grid.left
        anchors.margins: 40
        Text {
            Layout.alignment: Qt.AlignHCenter
            id: text_score
            text: qsTr("SCORE:")
            font.pixelSize: 30
            font.bold: true
        }
        Rectangle{
            id: scoar_rect
            width: rect_size
            height: width
            border.width: 2
        }
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

    ColumnLayout{
        id: next_figure
        Layout.bottomMargin: top_space
        anchors.left: main_grid.right
        anchors.margins: scoar.anchors.margins
        Text {
            id: text_next
            Layout.alignment: Qt.AlignHCenter
            text: qsTr("NEXT:")
            font.pixelSize: text_score.font.pixelSize
            font.bold: true
        }
        Rectangle{
            id: next_figure_rect
            width: rect_size
            height: width
            border.width: scoar_rect.border.width
        }

    }
}







