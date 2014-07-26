import QtQuick 2.0
import QtQuick.Window 2.1
import FourInARow 1.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1
import "style.js" as Style


QMLLoadScreen {
    id: loadScreen
    width: parent.width
//    width: parent.width> 12*Style.unit() ? 12*Style.unit() : parent.width
    height: parent.height

    signal backClicked

    /*
      Defines a ListElement of the Highscore ListView
    */
    Component {
        id: loadEntryDelegate
        Item {
            id: entryItem
            width: highscoreScreen.width-Style.unit()*.1
            height: Style.unit() + Style.lineWidth()

            Button {
                width: parent.width
                height: Style.unit()

                onClicked: loadScreen.loadGame(index)

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
                            text: player0 + " vs. " + player1
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

    onAddEntry: loadGameModel.append({ "player0": player0, "player1": player1, "index": index })
    onClear: loadGameModel.clear()

    property int testCounter: 0

    onBackClicked: {
        if (testCounter>10) {
            testCounter=0
            clear()
        }else{
            addEntry("Silke", "Paula", testCounter)
            testCounter += 1
        }
    }

    Column {
        anchors.fill: parent

        Item {
            id: optionsSpacer
            height: Style.unit()
            width: parent.width
        }

        Row {
            width: parent.width
            height: Style.unit() * 8
            clip: true

            Item {
                id: highScoreItem
                width: parent.width - Style.unit() * .1
                height: Style.unit()*6.5

                ListModel {
                    id: loadGameModel
                }

                ListView {
                    id: highscoreView
                    anchors.fill: parent
                    model: loadGameModel
                    delegate: loadEntryDelegate
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

                    opacity: highscoreView.dragging ? 1.0 : 0
                    color: Style.buttonBorderColor
                    width: parent.width
                    height: highscoreView.height>0 ? parent.height/highscoreView.contentHeight * parent.height : parent.height
                    y: highscoreView.contentY/highscoreView.contentHeight * parent.height
                }
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

                onClicked: loadScreen.backClicked()
            }

        }

    }

}

