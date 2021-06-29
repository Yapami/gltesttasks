import QtQuick 2.0

Item{
    property var number: (Math.random() * 1000000000000000000) % 3
    property var yPos
    x: 350
    y: yPos
    Rect_of_element{
        id: one
        colorNumber: number
    }

    Rect_of_element{
        id: two
        colorNumber: number
        anchors.left: one.right
    }

    Rect_of_element{
        id: three
        colorNumber: number
        anchors.right: one.left
    }

    Rect_of_element{
        id: four
        colorNumber: number
        anchors.top: one.bottom
    }

    focus: true

    Keys.onRightPressed: {
        if(element.x<425)
        element.x += 25
    }
    Keys.onLeftPressed: {
        if(element.x>425-250+75)
        element.x -= 25
    }
    Keys.onDownPressed: {
        if(element.yPos<25*21-50)
            element.yPos += 25
        else{
            focus = false
        }
    }
    Keys.onSpacePressed: {
        element.rotation += 90
    }
    Keys.onUpPressed: {
        element.rotation += 90
    }
}
