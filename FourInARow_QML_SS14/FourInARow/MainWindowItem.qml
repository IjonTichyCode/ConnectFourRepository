import QtQuick 2.0
import FourInARow 1.0
import "style.js" as Style

Item {
    id: mainWindowItem
    width: parent.width
    height: 10*Style.unit()

    property QMLMainWindow parentWindow
    property real screenChoiceX: 0



    states: [
        State {
            name: "STARTSCREEN"
            PropertyChanges {
                target: mainWindowItem
                screenChoiceX: 0
            }
        },
        State {
            name: "PLAYSCREEN"
            PropertyChanges {
                target: mainWindowItem
                screenChoiceX: -mainWindowItem.width
            }
        },
        State {
            name: "NEWGAME"
            PropertyChanges {
                target: mainWindowItem
                screenChoiceX: -2 * mainWindowItem.width
            }
        },
        State {
            name: "HIGHSCORE"
            PropertyChanges {
                target: mainWindowItem
                screenChoiceX: -3 * mainWindowItem.width
            }
        },
        State {
            name: "LOADSCREEN"
            PropertyChanges {
                target: mainWindowItem
                screenChoiceX: -4* mainWindowItem.width
            }
        }

    ]

    state: "STARTSCREEN"

    Row {
        width: parent.width
        height: parent.height
        x: screenChoiceX

        StartScreen {
            id: startScreen
            visible: true

            onNewGameClicked: mainWindowItem.state = "NEWGAME"
            onHighscoreClicked: mainWindowItem.state = "HIGHSCORE"
            onContinueClicked: mainWindowItem.state = "PLAYSCREEN"
            onLoadGameClicked: mainWindowItem.state = "LOADSCREEN"
        }

        PlayScreen {
            id: playScreen
            design: optionsPanel.optDesign
            visible: true

            onCancelClicked: mainWindowItem.state = "STARTSCREEN"
            onMenuClicked: mainWindowItem.state = "STARTSCREEN"
        }

        NewGameScreen {
            id: newGameScreen
            visible: true

            onCancelClicked: mainWindowItem.state = "STARTSCREEN"
            onStartClicked: mainWindowItem.state = "PLAYSCREEN"
        }

        HighscoreScreen {
            id: highscoreScreen
            visible: true

            onBackClicked: mainWindowItem.state = "STARTSCREEN"
        }

        LoadScreen {
            id: loadScreen
            visible: true

            onBackClicked: mainWindowItem.state = "STARTSCREEN"
        }

    }



    Options {
        id: optionsPanel
        visible: true
        z: 1

        onOptAntialiasingChanged: {
            console.log("antialias changed")
            parentWindow.setAntialiasing(optAntialiasing)
        }

        onOptFullscreenChanged: parentWindow.setFullscreen(optFullscreen)

    }

    CloseButton {
        id: closeButton
        property real position: optionsPanel.optFullscreen==true ? 1 : 0
        x: parent.width - Style.unit()*position
        z: 2

        onClicked: parentWindow.close()

        Behavior on position {
            PropertyAnimation {
                properties: "position"
                easing.type: Easing.InOutQuad
                duration: 420
            }
        }

    }

}
