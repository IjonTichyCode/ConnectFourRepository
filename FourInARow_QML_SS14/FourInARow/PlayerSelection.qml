import QtQuick 2.0
import QtQuick.Controls 1.1
import "style.js" as Style

Column {
    width: parent.width
    height: Style.unit() * 2
    property string playerId

    Text {
        color: Style.textColor
        text: qsTr("player") + " " + playerId + ":"
        width: parent.width
        height: Style.unit()
        font.pixelSize: Style.p()
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

    Row {
        id: playerSelection
        width: parent.width
        height: Style.unit()

        ComboBox {
            id: combo
            width: parent.width * .68
            height: parent.height
            currentIndex: 0
            model: [
                "kex", "kax", "knox"
            ]
        }

        Item {
            width: parent.width * .05
            height: parent.height
        }

        SimpleButton {
            label: qsTr("new")
            fontSize: Style.p()
            height: parent.height
            width: parent.width * .27
        }

    }

}

