import QtQuick 2.12
import QtQuick.Window 2.12



Window {
    id:mainWin
    visible: true
    width: 700
    height: 550
    title: qsTr("Hello World")
    maximumHeight: height
    minimumHeight: height
    maximumWidth: width
    minimumWidth: width

    Init{}
    property var yPos: 25
    Item{
        id: element
        x: 350
        y: yPos
        Rectangle{
            id: one
            width: 25
            height: 25
            color:"red"
            border.width: 1
        }
        Rectangle{
            id: two
            width: 25
            height: 25
            color:"red"
            border.width: 1
            anchors.left: one.right
        }

        Rectangle{
            id: three
            width: 25
            height: 25
            color:"red"
            border.width: 1
            anchors.right: one.left
        }

        Rectangle{
            id: four
            width: 25
            height: 25
            color:"red"
            border.width: 1
            anchors.top: one.bottom
        }
        focus: true
        Keys.onRightPressed: {
            if(element.x<425)
            element.x += 25
        }
        Keys.onLeftPressed: {
            if(element.x>250)
            element.x -= 25
        }
        Keys.onDownPressed: {
            mainWin.yPos += 25        }
    }
    Timer{
        id: timer
        interval: 1000/2
        repeat: true
        onTriggered: {mainWin.yPos = mainWin.yPos + 25}
        running: true
    }
}
