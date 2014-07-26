import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1
import "style.js" as Style

Item {
    width: parent.width
    height: Style.unit() * 1.5

    property string playerId

    Column {
        anchors.fill: parent

        Text {
            color: Style.textColor
            text: qsTr("player") + " " + playerId + ":"
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
                property string label: "Arthur"

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
                        color: control.pressed ? Style.buttonPressedColor : Style.backgroundColor

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

                            Item {
                                height: parent.height/2
                                width: parent.height
                                clip: true
                                y: height * 2/3

                                Rectangle {
                                    id: arrow
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    width: parent.width /2
                                    height: parent.width /2
                                    y: -height/2

                                    color: "transparent"
                                    border.color: Style.buttonBorderColor
                                    border.width: Style.lineWidth()

                                    transform: Rotation {
                                        angle: 45
                                        origin.x: arrow.width/2
                                        origin.y: arrow.height/2
                                    }

                                }
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
            }

        }

    }

    Component.onCompleted: {
        for (var i=0; i<15; ++i) {
            playerList.addEntry("Silke"+i, testCounter);
        }
    }

    PlayerList{
        id: playerList
        width: parent.width * 1.05
        height: Style.unit()*6
        visible: false

        onPlayerClicked: {
            visible = false
            playerDropdownButton.label = player
        }

    }

}

