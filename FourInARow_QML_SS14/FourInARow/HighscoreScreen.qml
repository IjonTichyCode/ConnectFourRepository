import QtQuick 2.2
import QtQuick.Window 2.1
import FourInARow 1.0
import "style.js" as Style


QMLHighscoreScreen {
    id: highscoreScreen
    width: parent.width
//    width: parent.width> 12*Style.unit() ? 12*Style.unit() : parent.width
    height: parent.height

    signal backClicked

    /*
      Defines an ListElement of the Highscore ListView
    */
    Component {
        id: highscoreEntryDelegate
        Item {
            width: highscoreScreen.width-Style.unit()*.1
            height: Style.unit() * 1.25

            Row {
                width: parent.width
                height: Style.unit()

                Text {
    //                y: Style.unit() * .125
                    color: Style.textColor
                    text: player + ":"
                    width: parent.width *.6
                    height: Style.unit()
                    font.pixelSize: Style.p()
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    color: Style.textColor
                    text:  wins + "/" + losses + "/" + ratio.toFixed(2)
                    width: parent.width *.4
                    height: Style.unit()
                    font.pixelSize: Style.p()
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Seperator {
                y: Style.unit()
            }
        }

    }

    onAddEntry: highscoreModel.append({ "player": player, "wins": wins, "losses": losses, "ratio": ratio })
    onClear: highscoreModel.clear()

    property int testCounter: 0

    onBackClicked: {
        if (testCounter>10) {
            testCounter=0
            clear()
        }else{
            testCounter += 1
            addEntry("bla", 5, 2, 2.5)
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
            id: header
            height: Style.unit()*1.5 - Style.lineWidth()*2
            width: parent.width

            Text {
                color: Style.textColor
                text: qsTr("player")
                width: parent.width * .6
                height: parent.height
                font.pixelSize: Style.h3()
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Column {
                width: parent.width * .4
                height: parent.height

                Text {
                    color: Style.textColor
                    height: parent.height/3
                    width: parent.width
                    font.pixelSize: Style.tinyText()
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: qsTr("wins") + " /"
                }
                Text {
                    color: Style.textColor
                    height: parent.height/3
                    width: parent.width
                    font.pixelSize: Style.tinyText()
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: qsTr("losses") + " /"
                }
                Text {
                    color: Style.textColor
                    height: parent.height/3
                    width: parent.width
                    font.pixelSize: Style.tinyText()
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: qsTr("ratio")
                }
            }
        }

        Rectangle  {
            width: parent.width
            height: Style.lineWidth()*2
            color: Style.seperatorColor
        }

        Row {
            width: parent.width
            height: Style.unit() * 6.5
            clip: true

            Item {
                id: highScoreItem
                width: parent.width - Style.unit() * .1
                height: Style.unit()*6.5

                ListModel {
                    id: highscoreModel
                }

                ListView {
                    id: highscoreView
                    anchors.fill: parent
                    model: highscoreModel
                    delegate: highscoreEntryDelegate
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

                onClicked: highscoreScreen.backClicked()
            }

        }

    }

}
