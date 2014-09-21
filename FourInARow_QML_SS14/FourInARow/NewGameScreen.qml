import QtQuick 2.0
import QtQuick.Controls 1.2
import FourInARow 1.0
import "style.js" as Style

QMLNewGameScreen {
    id: newGameScreen
    visible: true

    width: parent.width
    height: parent.height

    property int columns: columnsControl.value
    property int rows: rowsControl.value

    property int player0Id;
    property int player1Id;
    property string cpuPlayerTag: " (CPU)"

    onSelectPlayers: {
        newGameScreen.player0Id = player0Id
        newGameScreen.player1Id = player1Id
    }

    onSetBoardSizeOption: {
        columnsControl.value = columns
        rowsControl.value = rows
    }

    onSetTimerOption: timerSelection.setTimer(useTimer, maxTime)

//    color: Style.backgroundColor

    signal startClicked
    signal cancelClicked

    Component.onCompleted: {
        qmlComponentCompleted()
        populate()
    }

    onAddEntry: {
        var name = player + (isCpu ? cpuPlayerTag : "")

        playerList0.addEntry(name, playerIndex)
        playerList1.addEntry(name, playerIndex)
        if (playerIndex==player0Id) {
            playerSelection0.player = name
            playerSelection0.playerId = playerIndex
        }
        if (playerIndex==player1Id) {
            playerSelection1.player = name
            playerSelection1.playerId = playerIndex
        }
    }

    onStartClicked: {
        setupNewGame()
        setPlayers(playerSelection0.playerId, playerSelection1.playerId)
        setBoardSize(columnsControl.value, rowsControl.value)
        setTimer(timerSelection.checked, timerSelection.time)
        console.log("usetimer: " + timerSelection.checked)
        startGame()
    }

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
                    selectionId: 1
                    playerId: 1
                    playerList: playerList0
//                    z:2
                    z: 2
//                    zOffset: 2
                    onNewPlayer: newPlayerDialog.visible = true
                }
                PlayerSelection {
                    id: playerSelection1
                    selectionId: 2
                    playerId: 2
                    playerList: playerList1
//                    z:1
                    z:1
//                    zOffset: 4
                    onNewPlayer: newPlayerDialog.visible = true
                }
                Seperator {
                    width: newGameScreen.width
                    anchors.horizontalCenter: parent.horizontalCenter
                }


                BoardSizeControl {
                    id: columnsControl
                    value: 7
                    label: qsTr("columns")
                }
                BoardSizeControl {
                    id: rowsControl
                    value: 6
                    label: qsTr("rows")
                }
                Seperator {
                    width: newGameScreen.width
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                TimerSelection{
                    id: timerSelection
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
            playerSelection0.playerId = index
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
            playerSelection1.playerId = index
        }

    }

    NewPlayerDialog {
        id: newPlayerDialog
        visible: false
        onNewPlayerClicked: addNewPlayer(name, isCpu, level)
    }
}
