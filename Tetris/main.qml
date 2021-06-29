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

    Init_Board{}
    Element{
        id: element
        yPos: 25
    }

    Timer{
        id: timer
        interval: 1000/2
        repeat: true
        onTriggered: {
            if(element.yPos<25*21-50)
                element.yPos += 25
            else{
                element.focus = false
            }
        }
        running: true
    }
}
