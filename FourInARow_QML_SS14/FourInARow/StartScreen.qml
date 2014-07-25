import QtQuick 2.0
import FourInARow 1.0
import "style.js" as Style

Column {
    id: startScreen
    visible: true

//    color: Style.backgroundColor
    width: parent.width
    height: parent.height
//    anchors.fill: parent

    signal newGameClicked
    signal loadGameClicked
    signal highscoreClicked
    signal continueClicked

    Item {
        id: optionsSpacer
        width: parent.width
        height: Style.unit()
    }

    Title {
        id: header
        height: Style.unit() * 3.5
        width: parent.width * .85
        anchors.horizontalCenter: parent.horizontalCenter
        columns: grid.width>2*grid.height ? 2 : 1
    }

    Grid {
        id: grid
//        anchors.bottom: bottomSpacer.top

        anchors.horizontalCenter: parent.horizontalCenter

        width: parent.width * .85
        height: Style.unit() * 5

        columns: width>2*height ? 2 : 1
        rows: 4/columns
        spacing: parent.height * .02

        property real buttonHeight: (height-(rows-1)*spacing)/rows
        property real buttonWidth: (width-(columns-1)*spacing)/columns

        SimpleButton {
            id: continueButton
            label: qsTr("continue")

            width: grid.buttonWidth
            height: grid.buttonHeight
            onClicked: startScreen.continueClicked()
        }

        SimpleButton {
            id: newGameButton
            label: qsTr("new game")

            width: grid.buttonWidth
            height: grid.buttonHeight
            onClicked: startScreen.newGameClicked()
        }

        SimpleButton {
            id: loadGameButton
            label: qsTr("load game")

            width: grid.buttonWidth
            height: grid.buttonHeight
            onClicked: startScreen.loadGameClicked()
        }

        SimpleButton {
            id: highScoreButton
            label: qsTr("highscore")

            width: grid.buttonWidth
            height: grid.buttonHeight
            onClicked: startScreen.highscoreClicked()
        }

    }

}

