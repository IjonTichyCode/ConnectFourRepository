import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1
import "style.js" as Style

Item {
    width: parent.width
    height: Style.unit() * 1.5

    property int playerId
//    property real zOffset: 0
    property PlayerList playerList
    property string player: "Arthur"

    // first or second player of the game
    property int selectionId;

    signal newPlayer

    Column {
        anchors.fill: parent

        Text {
            color: Style.textColor
            text: qsTr("player") + " " + selectionId + ":"
            width: parent.width
            height: Style.unit()*.75
            font.pixelSize: Style.p()
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }

        Row {
            id: playerSelection
            width: parent.width
            height: Style.unit()*.75


            Button {
                id: playerDropdownButton
                height: parent.height
                width: parent.width * .68
                property string label: player

                onClicked: playerList.visible = true

                style: ButtonStyle {
                    background: Rectangle {
                        anchors.fill: parent


                        border.color: Style.buttonBorderColor
                        border.width: Style.lineWidth()

                        // workaround: if someone flicks the list of all games to load, the button is pressed for one
                        // moment. 70ms are short enough to show a button pressed color and long enough to hide the
                        // color when flicking the list
                        Behavior on color {
                            PropertyAnimation {
                                properties: "color"
                                easing.type: Easing.InExpo
                                duration: 70
                            }
                        }
                        color: control.pressed ? Style.buttonPressedColor : Style.buttonColor

                        Row {
                            anchors.fill: parent

                            Text {
                                height: parent.height
                                width: parent.width-parent.height
                                color: Style.textColor
                                text: playerDropdownButton.label
                                font.pixelSize: Style.p()
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }

                            DragArrow {
                                width: parent.height
                                height: parent.height
                                lineWidth: Style.lineWidth()
                                color: Style.buttonBorderColor
                                direction: -1
                            }
                        }


                    }
                }
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
                onClicked: newPlayer()
            }

        }

    }

}

