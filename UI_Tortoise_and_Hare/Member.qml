import QtQuick 2.0

Rectangle{
    id: _rect
    radius: 10
    property string _rect_text: ""
    border{
        color: "black"
        width: 1
    }

    width: 40
    height: 40
    y: 10

    Text {
        anchors.centerIn: _rect
        color: "white"
        text: qsTr(_rect_text)
        font.pointSize: 15
    }
}
