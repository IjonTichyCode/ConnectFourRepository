import QtQuick 2.2
import QtQuick.Window 2.1
import FourInARow 1.0
import QtMultimedia 5.0
import "style.js" as Style


Item {

//    anchors.fill: parent
    width: parent.width
    height: parent.height
    id: highscoreScreen

    signal backClicked

    Column {
        anchors.fill: parent

        Item {
            id: optionsSpacer
            height: Style.unit()
            width: parent.width
        }

        Item {
           id: highScoreItem
           width: parent.width
           height: Style.unit()*8

           Rectangle {
               color: "cyan"
               anchors.fill: parent
           }
        }

        Row {
            id: buttonBar
            width: parent.width
            height: Style.unit()

            SimpleButton {
                id: saveButton
                label: qsTr("back")

                height: parent.height
                width: parent.width

                onClicked: highscoreScreen.backClicked()
            }

        }

    }

}
