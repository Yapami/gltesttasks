import QtQuick 2.0
import QtQuick.Shapes 1.12



Shape {
    property var sY
    property var sX
    property var fY
    property var fX
    property var w

    ShapePath {
        strokeColor: "black"
        strokeWidth: w
        startX: sX
        startY: sY
        PathLine { x: fX; y: fY }
    }
}



