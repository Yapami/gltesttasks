import QtQuick 2.0

Item {
    Text {
        id: text_score
        text: qsTr("SCORE:")
        y: 80
        x: 57
        font.pixelSize: 30
        font.bold: true
    }
    Text {
        id: text_next
        text: qsTr("NEXT:")
        y: 80
        x: 547
        font.pixelSize: 30
        font.bold: true
    }
}

