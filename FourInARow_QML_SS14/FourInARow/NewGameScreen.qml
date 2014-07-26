import QtQuick 2.0
import QtQuick.Controls 1.2
import "style.js" as Style

Rectangle {
    id: newGameScreen
    visible: true

    width: parent.width
    height: parent.height

    color: Style.backgroundColor

    signal startClicked
    signal cancelClicked

    property int testCounter: 0

    Column {
        anchors.fill: parent

        Item {
            id: optionsSpacer
            height: Style.unit()
            width: parent.width
        }

        Row {
            width: parent.width
            height: Style.unit()*8

            Item {
                width: parent.width * .08
                height: parent.height
            }

            Column {
                id: optionsBox
                width: parent.width * .84
                height: parent.height

                PlayerSelection {
                    playerId: "1"
                    z:2
                }

                PlayerSelection {
                    playerId: "2"
                    z:1
                }

                Seperator {
                    width: newGameScreen.width
                    anchors.horizontalCenter: parent.horizontalCenter
                }

            }
        }

        Row {
            id: buttonBar
            width: parent.width
            height: Style.unit()

            SimpleButton {
                label: qsTr("start")
                height: parent.height
                width: parent.width/2
                onClicked: newGameScreen.startClicked()
            }

            SimpleButton {
                label: qsTr("cancel")
                height: parent.height
                width: parent.width/2
                onClicked: newGameScreen.cancelClicked()
            }
        }

    }

//    Column {
//        anchors.fill: parent

//        TextField {
//            width: parent.width
//            height: parent.height * .1
//        }
//    }
}
