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
        },
        State {
            name: "SQLSCREEN"
            PropertyChanges {
                target: mainWindowItem
                screenChoiceX: -5* mainWindowItem.width
            }
        }

    ]

    state: "STARTSCREEN"

    function preClose() {
        if (state=="PLAYSCREEN") {
            playScreen.saveGame(playScreen.time)
        }
    }

    Row {
        width: parent.width
        height: parent.height
        x: screenChoiceX

        StartScreen {
            id: startScreen
            visible: true

            onNewGameClicked: mainWindowItem.state = "NEWGAME"
            onHighscoreClicked: mainWindowItem.state = "HIGHSCORE"
            onContinueClicked: loadScreen.loadLatestGame()
//            onContinueClicked: mainWindowItem.state = "SQLSCREEN"
            onLoadGameClicked: mainWindowItem.state = "LOADSCREEN"
        }

        PlayScreen {
            id: playScreen
            design: optionsPanel.optDesign
            visible: true

            onCancelClicked: {
                mainWindowItem.state = "STARTSCREEN"
                playScreen.clear()
            }

            onMenuClicked: {
                mainWindowItem.state = "STARTSCREEN"
                playScreen.clear()
            }

            onGameSaved: {
                loadScreen.clear()
                loadScreen.populate()
            }
            onHighscoreChanged: {
                highscoreScreen.clear();
                highscoreScreen.populate();
            }
        }

        NewGameScreen {
            id: newGameScreen
            visible: true
//            onColumnsChanged: playScreen.columns = newGameScreen.columns
//            onRowsChanged: playScreen.rows = newGameScreen.rows

            onCancelClicked: mainWindowItem.state = "STARTSCREEN"
            onStartClicked: {
                playScreen.columns = newGameScreen.columns
                playScreen.rows = newGameScreen.rows
                mainWindowItem.state = "PLAYSCREEN"
                playScreen.clear()
                playScreen.endLoadGame()
            }

            onNewPlayerAdded: {
                highscoreScreen.clear()
                highscoreScreen.populate()
            }

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
            onStartLoadGame: playScreen.startLoadGame()
            onEndLoadGame: {
                playScreen.endLoadGame()
                mainWindowItem.state = "PLAYSCREEN"
            }
            onSetBoardDimension: {
                playScreen.columns = columns
                playScreen.rows = rows
            }
        }

        SQLScreen {
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
        onOptColor0Changed: {
            console.log("MainWindowItem: onOptColor0Changed")
            playScreen.color0 = optColor0
        }
        onOptColor1Changed: {
            console.log("MainWindowItem: onOptColor1Changed")
            playScreen.color1 = optColor1
        }

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

    function loadOptions() {
        optionsPanel.qmlComponentCompleted()
    }

}
