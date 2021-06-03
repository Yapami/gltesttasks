import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 1080
    height: 720
    title: qsTr("RACE")
    id: mainWin


    property var _Tx : 10
    property var _Hx : 10
    property var _Rx : 10
    property var _Fx : 10

    Label{
        id: text
        width: 400
        height: 100
        anchors.centerIn: parent
        visible: false
        color: "Green"
        wrapMode: Text.WordWrap
        font.family: "Times"
        font.pixelSize: 20
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
    }


    Button{
    id: start
    text: "START"
    anchors.centerIn: parent
    onClicked: {
        _Tx = 10
        _Hx = 10
        _Rx = 10
        _Fx = 10
        timer.running = true
        start.visible = false
        text.visible = false
    }
    }

    property var pow : 14

    Line{sX: 5; sY: 0; fX: 5; fY: 280; w: 10}
    Line{sX: 70*pow; sY: 0; fX: 70*pow; fY: 280; w: 10}
    Line{sX: 0; sY: 290; fX: 70*pow; fY: 290; w: 10}

    Member{
        x : _Tx
        y: 10
        color: "red"
        _rect_text: "T"
    }

    Member{
        x : _Hx
        y: 80
        color: "blue"
        _rect_text: "H"
    }


    Member{
        x : _Rx
        y: 150
        color: "purple"
        _rect_text: "R"
    }

    Member{
        x : _Fx
        y: 220
        color: "green"
        _rect_text: "F"
    }


    property var state
    Timer{
        id: timer
        interval: 1000/5
        onTriggered:{
            state = race.update()
            mainWin._Tx += race.getShift(0)*pow
            mainWin._Hx += race.getShift(1)*pow
            mainWin._Rx += race.getShift(2)*pow
            mainWin._Fx += race.getShift(3)*pow
            if(!state){
                race.finish()
                timer.running = false
                text.text = qsTr(race.getWinner())
                text.visible = true
                start.visible = true
            }
        }
        repeat: true
    }
}
