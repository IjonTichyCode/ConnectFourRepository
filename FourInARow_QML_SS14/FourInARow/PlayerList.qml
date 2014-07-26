import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1
import "style.js" as Style

Rectangle {
    id: playerList
    anchors.horizontalCenter: parent.horizontalCenter

//    color: Style.backgroundColor
    color: "#FF000000"
    border.color: Style.seperatorColor
    border.width: Style.lineWidth() * 2

    signal playerClicked(string player, int index)

    function addEntry(player, index) {
        playerListModel.append({ "player": player, "index": index })
    }

    function clear() {
        playerListModel.clear()
    }

    Component {
        id: playerListEntryDelegate

        Item {
            id: entryItem
            width: playerListItem.width
            height: Style.unit() + Style.lineWidth()

            Button {
                width: parent.width
                height: Style.unit()

                onClicked: playerClicked(player, index);

                style: ButtonStyle {
                    background: Item {
                        anchors.fill: parent

                        Rectangle {
                            anchors.fill: parent

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
                        }

                        Text {
                            anchors.fill: parent
                            color: Style.textColor
                            text: player
                            font.pixelSize: Style.p()
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
            }

            Seperator {
                height: Style.lineWidth()
                y: Style.unit()
            }
        }
    }

    Row {
        width: parent.width - 4*Style.lineWidth()
        height: parent.height - 4*Style.lineWidth()
        anchors.centerIn: parent
        clip: true

        Item {
            id: playerListItem
            width: parent.width - Style.unit() * .1
            height: parent.height

            ListModel {
                id: playerListModel
            }

            ListView {
                id: playerListView
                anchors.fill: parent
                model: playerListModel
                delegate: playerListEntryDelegate
                boundsBehavior: Flickable.StopAtBounds
            }
        }

        Item {
            id: scrollBar
            width: Style.unit()*.1
            height: parent.height

            Rectangle {

                Behavior on opacity {
                    PropertyAnimation {
                        properties: "opacity"
                        easing.type: Easing.InOutQuad
                        duration: 250
                    }
                }

                opacity: playerListView.dragging ? 1.0 : 0
                color: Style.buttonBorderColor
                width: parent.width
                height: playerListView.height>0 ? parent.height/playerListView.contentHeight * parent.height : parent.height
                y: playerListView.contentY/playerListView.contentHeight * parent.height
            }
        }
    }

}
