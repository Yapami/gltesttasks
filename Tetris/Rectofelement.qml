import QtQuick 2.0

Rectangle{
    property int colorNumber
    width: mainWin.gridrect_size
    height: width
    border.width: 1
    color: {
        if(colorNumber === 0)
            return "red"
        if(colorNumber === 1)
            return "blue"
        if(colorNumber === 2)
            return "green"
    }
}



