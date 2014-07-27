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
                    id: playerSelection0
                    playerId: "1"
                    playerList: playerList0
//                    z:2
                    z: 2
//                    zOffset: 2
                }
                PlayerSelection {
                    id: playerSelection1
                    playerId: "2"
                    playerList: playerList1
//                    z:1
                    z:1
//                    zOffset: 4
                }
                Seperator {
                    width: newGameScreen.width
                    anchors.horizontalCenter: parent.horizontalCenter
                }


                BoardSizeControl {
                    value: 7
                    label: qsTr("columns")
                }
                BoardSizeControl {
                    value: 6
                    label: qsTr("rows")
                }
                Seperator {
                    width: newGameScreen.width
                    anchors.horizontalCenter: parent.horizontalCenter
                }


                OptionsSwitch {
                    width: parent.width
                    height: Style.unit()* .75
                    text: qsTr("move timer")
                    imageSrc: "/resources/clock.svg"
                    padding: 0
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

    /************************MODAL DIALOGS********************************/

    PlayerList{
        id: playerList0
        width: parent.width
        height: parent.height-Style.unit()
        y: Style.unit()
        visible: false
//        z: zOffset

        onPlayerClicked: {
            visible = false
            playerSelection0.player = player
        }

    }

    PlayerList{
        id: playerList1
        width: parent.width
        height: parent.height-Style.unit()
        y: Style.unit()
        visible: false
//        z: zOffset

        onPlayerClicked: {
            visible = false
            playerSelection1.player = player
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
