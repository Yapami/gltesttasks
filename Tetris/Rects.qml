import QtQuick 2.0

Item {
    anchors.fill: parent

    Rectangle{
        id: scoar
        width: 150
        height: width
        border.width: 2
        x: 35
        y: 120
    }

    Rectangle{
        id: next_figure
        width: 150
        height: width
        border.width: 2
        x: 515
        y: 120
    }
    Grid{
        id: main_grid
        anchors.centerIn: parent
        rows: 20
        columns: 10
        Repeater{
            model: 200
            Rectangle{
                width: 25
                height: 25
                border.width: 1
            }
        }
    }
}
