import QtQuick 2.2
import QtMultimedia 5.0

Item {
    id: token

    signal makeMove(int column)
    signal drop(int column, int row, real time)
    signal winDrop(int column, int row, real time)
    signal tieDrop(int column, int row, real time)

    property real edgeLength: 50
    property variant imageSources:
        ["/resources/token0.png", "/resources/token1.svg", "/resources/token2.svg", "resources/tokenWin.svg", "resources/tokenTie.svg"]

    property color color: "yellow"
    property int design: 0
    property bool interactive: true
    property real dropTime: 0
    property SoundEffect bounce
    property SoundEffect slide
    property SoundEffect error
    property real column: 0
    property real row: 0
    property real errorRow: 0

    onDrop: {
        dropTime = time
        token.column = column
        token.row = row
        interactive = false
        token.slide.play()
        soundTimer.interval = dropTime*.365
        soundTimer.start();
    }

    onWinDrop: {
        dropTime = time
        token.column = column
        token.row = row
        interactive = false
    }

    function showError() {
        dropTime = 150
        errorRow = .5
        errorAnimationTimer.start()
    }

    x: column * edgeLength
    y: parent.height - (row-errorRow+1) * edgeLength;
    z: -1
    width: edgeLength
    height: edgeLength

    Behavior on row {
        PropertyAnimation {
            properties: "row"
            easing.type: Easing.OutBounce
            duration: dropTime
        }
    }

    Behavior on errorRow {
        PropertyAnimation {
            properties: "errorRow"
            easing.type: Easing.InQuad
            duration: dropTime
        }
    }

    Timer {
        id: soundTimer
        interval: dropTime;
        running: false;
        repeat: false;
        property int bounceCount: 0

        onTriggered: {
            ++bounceCount
            bounce.play()
            switch (bounceCount) {
                case 1:
                    interval = dropTime*0.37
                    start()
                    break
                case 2:
                    interval = dropTime*0.17
                    start()
                    break
                case 3:
                    stop()
                    slide.stop()
                    break
            }
        }
    }

    Timer {
        id: errorAnimationTimer
        interval: dropTime;
        running: false;
        repeat: false;

        onTriggered: errorRow = 0
    }

    Rectangle {
        width: edgeLength * .9
        height: edgeLength * .9
        radius: edgeLength * .45
        color: token.color
        anchors.centerIn: token

        Image {
            id: image
            antialiasing: true
            anchors.fill: parent
            source: token.imageSources[design]
        }
    }

    MouseArea {
        enabled: interactive
        anchors.fill: parent
        onReleased: {
            token.column = Math.round( token.x/token.edgeLength )
            token.x = Qt.binding(
                            function() {
                                return token.column * edgeLength;
                            }
                        )
        }

        onClicked: token.makeMove(token.column)  //console.log("clicked")

        drag {
            target: token
            axis: Drag.XAxis
            minimumX: 0
            maximumX: token.parent.width - edgeLength
        }

    }

}
