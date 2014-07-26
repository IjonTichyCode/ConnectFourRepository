import QtQuick 2.2
import QtQuick.Window 2.1
import FourInARow 1.0
import QtMultimedia 5.0
import "style.js" as Style


QMLPlayScreen {

    width: parent.width
    height: parent.height
    id: playScreen

    signal saveClicked
    signal menuClicked
    signal cancelClicked

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
               z: 2
           }
        }

        Item {
            id: statusBar
            width: parent.width
            height: Style.unit()

        }

        Row {
            id: buttonBar
            width: parent.width
            height: Style.unit()

            SimpleButton {
                id: saveButton
                label: qsTr("save")

                height: parent.height
                width: parent.width/3
                onClicked: playScreen.saveClicked()
            }

            SimpleButton {
                id: menuButton
                label: qsTr("menu")

                height: parent.height
                width: parent.width/3

                onClicked: playScreen.menuClicked()
            }

            SimpleButton {
                id: cancelButton
                label: qsTr("cancel")

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

            onMakeMove: {
                playScreen.makeMove(column)
            }

        }
    "

    property variant playerColors: ["red", "yellow"]



    onDropToken: {
        token.drop(column, row, Math.sqrt(board.dimension.y-row+.5)*800.0)
    }

    onSetupToken: {
        var t = Qt.createQmlObject(newTokenCode, board, "/")
        t.color = playerColors[player]
        t.column = column
        t.row = row
    }

    onNewInteractiveToken: {
        token = Qt.createQmlObject(newTokenCode, board, "/")
        token.row = board.dimension.y + .5
        token.column = Math.round(board.dimension.x /2)-1
        token.color = playerColors[player]
        token.bounce = bounceEffects[player]
        token.slide = slideEffects[player]
    }

    Component.onCompleted: {
        playScreen.newInteractiveToken(0,false)
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
}
