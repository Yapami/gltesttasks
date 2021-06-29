import QtQuick 2.0

Rectangle{
    property int colorNumber
    width: 25
    height: width
    border.width: 1
    color: chooseColor(colorNumber)
    function chooseColor()
    {
        if(colorNumber === 0)
            return "red"
        if(colorNumber === 1)
            return "blue"
        if(colorNumber === 2)
            return "yellow"
    }
}

