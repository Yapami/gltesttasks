import QtQuick 2.12
import QtQuick.Window 2.12
import Qt.labs.settings 1.0


Window {
    id: mainWin
    visible: true
    width: 700
    height: 550
    title: qsTr("Tetris")
    maximumHeight: height
    minimumHeight: height
    maximumWidth: width
    minimumWidth: width
    Settings {
           property alias x: mainWin.x
           property alias y: mainWin.y
    }
    property var gridrect_size: 25

    Initboard{}
    Element{
        id: element
        y_pos: gridrect_size
    }

    Timer{
        id: timer
        interval: 1000/2 //2 frame per second
        repeat: true
        onTriggered: {
            if(element.y_pos<25*21-50)
                element.y_pos += gridrect_size
            else{
                element.focus = false
            }
        }
        running: true
    }
}
