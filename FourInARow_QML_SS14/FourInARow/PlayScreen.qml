import QtQuick 2.2
import QtQuick.Window 2.1
import FourInARow 1.0
import QtMultimedia 5.0
import "style.js" as Style


QMLPlayScreen {

    width: parent.width
    height: parent.height
    property int columns: 7
    property int rows: 6
    property int time: 0
    id: playScreen

    property bool clearFlag: false

    signal saveClicked
    signal menuClicked
    signal cancelClicked

    onSaveClicked: {
        saveGame(time)
    }

    onCancelClicked: {
        moveTimer.stop()
    }

    onMenuClicked: {
        saveGame(time)
        moveTimer.stop()
    }

    onDropToken: {
        token.drop(column, row, Math.sqrt(board.dimension.y-row+.5)*800.0)
    }

    onRejectMove: {
        rejectMoveEffect.play()
        token.showError()
    }

    onPlayerWon: {
        var t0 = Qt.createQmlObject(newTokenCode, board, "/")
        var t1 = Qt.createQmlObject(newTokenCode, board, "/")
        var t2 = Qt.createQmlObject(newTokenCode, board, "/")
        var t3 = Qt.createQmlObject(newTokenCode, board, "/")
        t0.color = "yellow"; t1.color = "yellow"; t2.color = "yellow"; t3.color = "yellow"
        t0.column=col0; t1.column=col1; t2.column=col2; t3.column=col3
        var row = board.dimension.y + .5
        t0.row=row; t1.row=row; t2.row=row; t3.row=row
        t0.design=3; t1.design=3; t2.design=3; t3.design=3
        t0.winDrop(col0,row0,Math.sqrt(board.dimension.y-row0+.5)*800.0)
        t1.winDrop(col1,row1,Math.sqrt(board.dimension.y-row1+.5)*800.0)
        t2.winDrop(col2,row2,Math.sqrt(board.dimension.y-row2+.5)*800.0)
        t3.winDrop(col3,row3,Math.sqrt(board.dimension.y-row3+.5)*800.0)
        moveTimer.stop()
        wonEffect.play()
    }

    onTie: {
        var t0 = Qt.createQmlObject(newTokenCode, board, "/")
        var t1 = Qt.createQmlObject(newTokenCode, board, "/")
        t0.color = "red"; t1.color="red"
        var row = board.dimension.y + 2
        t0.row=row; t1.row=row
        t0.design=4; t1.design=4
        row-=2
        var center = (board.dimension.x-1)/2
        t0.winDrop(center-.5,row,1000)
        t1.winDrop(center+.5,row,1000)
        moveTimer.stop()
        tieEffect.play()
    }

    onSetStatusMessage: statusBar.text = message

    onSetupToken: {
        var t = Qt.createQmlObject(newTokenCode, board, "/")
        t.color =   Qt.binding(
                        function() {
                            return playerColors[player];
                        }
                    )
        t.column = column
        t.row = row
        t.interactive = false
    }

    onNewInteractiveToken: {
        token = Qt.createQmlObject(newTokenCode, board, "/")
        token.row = board.dimension.y + .5
        token.column = Math.round(board.dimension.x /2)-1
        token.interactive = (isCpu ? false : true)
        token.color =   Qt.binding(
                            function() {
                                return playerColors[player];
                            }
                        )
        token.bounce = bounceEffects[player]
        token.slide = slideEffects[player]
    }

    onClear: {
        playScreen.clearFlag = true; playScreen.clearFlag = false
    }

    onSetTimer: {
        if (time==0) {
            playScreen.time=""
        }else{
            playScreen.time = time;
            moveTimer.start()
        }
    }

    Column {
        anchors.fill: parent

        Item {
            id: optionsSpacer
            height: Style.unit()
            width: parent.width
        }

        Item {
           id: playZone
           width: parent.width
           height: Style.unit()*7

           Board {
               id: board
               dimension: Qt.vector2d(columns, rows)
               z: 2
               design: playScreen.design
           }
        }

        Item {
            height: Style.unit()
            width: parent.width * .84
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                id: clock
                width: parent.width
                height: parent.height
                text: time
                font.pixelSize: Style.p()
                color: Style.textColor
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }

            Text {
                id: statusBar
                width: parent.width
                height: parent.height
                text: ""
                font.pixelSize: Style.p()
                color: Style.textColor
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
            }

        }

        Row {
            id: buttonBar
            width: parent.width
            height: Style.unit()

            SimpleButton {
                id: saveButton
                label: qsTr("save")
                fontSize: Style.p()

                height: parent.height
                width: parent.width/3
                onClicked: playScreen.saveClicked()

            }

            SimpleButton {
                id: menuButton
                label: qsTr("menu")
                fontSize: Style.p()

                height: parent.height
                width: parent.width/3

                onClicked: playScreen.menuClicked()
            }

            SimpleButton {
                id: cancelButton
                label: qsTr("cancel")
                fontSize: Style.p()

                height: parent.height
                width: parent.width/3

                onClicked: playScreen.cancelClicked()
            }
        }

    }

    property Token token
    property int design: 0
    property string newTokenCode:
    "
        import QtQuick 2.2
        Token {
            edgeLength: board.tileWidth;
            design: playScreen.design
            property bool clearFlag: playScreen.clearFlag

            onClearFlagChanged: {
                if (clearFlag) {
                    destroy()
                }
            }

            onMakeMove: {
                playScreen.makeMove(column, playScreen.time)
            }

        }
    "

    property variant playerColors: [color0, color1]
    property color color0
    property color color1

    SoundEffect {
        id: rejectMoveEffect
        source: "resources/invalidMove.wav"
    }

    SoundEffect {
        id: wonEffect
        source: "resources/win.wav"
    }

    SoundEffect {
        id: tieEffect
        source: "resources/tie.wav"
    }

    property list<SoundEffect> bounceEffects: [
        SoundEffect {
            source: "resources/bounce0.wav"
        },
        SoundEffect {
            source: "resources/bounce1.wav"
        }
    ]

    property list<SoundEffect> slideEffects: [
        SoundEffect {
            source: "resources/slide0.wav"
        },
        SoundEffect {
            source: "resources/slide1.wav"
        }
    ]

    Timer {
        id: moveTimer
        running: false;
        repeat: false;
        interval: 1000

        onTriggered: {
            --time;
            if (time<=0) {
                playScreen.timerExpired();
            }else{
                start()
            }
        }
    }
}
