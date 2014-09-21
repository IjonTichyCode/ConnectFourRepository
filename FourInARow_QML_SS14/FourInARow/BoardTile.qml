import QtQuick 2.0
import FourInARow 1.0

QMLBoardTile {
//    property color myColor: "yellow"

    property real edgeLength: 50
    property int design: 0
    property variant imageSources:
        ["/resources/boardTile0.png", "/resources/boardTile1.svg", "/resources/boardTile2.svg"]

    width: edgeLength
    height: edgeLength

    Image {
        id: image
        antialiasing: true
        anchors.fill: parent
        source: imageSources[design]
    }
}
