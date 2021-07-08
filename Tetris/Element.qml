import QtQuick 2.0

Item{
    property var number: Math.floor(Math.random()*3)
    property var y_pos
    property var rotationt_size: 90
    property var grid_width: 250
    property var right_side_x_pos: 425

    x: 350
    y: y_pos
    Rectofelement{
        id: first
        colorNumber: number
    }

    Rectofelement{
        id: second
        colorNumber: number
        anchors.left: first.right
    }

    Rectofelement{
        id: third
        colorNumber: number
        anchors.right: first.left
    }

    Rectofelement{
        id: fourth
        colorNumber: number
        anchors.top: first.bottom
    }

    focus: true

    Keys.onRightPressed: {
        if(element.x<right_side_x_pos) //will be chenged
            element.x += mainWin.gridrect_size
    }
    Keys.onLeftPressed: {
        if(element.x>right_side_x_pos-grid_width+mainWin.gridrect_size*3) //will be chenged
            element.x -= mainWin.gridrect_size
    }
    Keys.onDownPressed: {
        if(element.y_pos<mainWin.gridrect_size*19) //will be chenged
            element.y_pos += mainWin.gridrect_size
        else{
            focus = false
        }
    }
    Keys.onSpacePressed: {
        element.rotation += rotationt_size
    }
    Keys.onUpPressed: {
        element.rotation += rotationt_size
    }
}
