import QtQuick 2.0
import FourInARow 1.0

QMLBoardTile {
    property color myColor: "yellow"

    property real edgeLength: 50
//    width: parent.height/ rows;
//    height: parent.height/ rows;
    width: edgeLength
    height: edgeLength

//    Rectangle {
//        color: "yellow"
//        width: parent.width*.9
//        height: parent.height*.9
//        radius: parent.width* .45
//        anchors.centerIn: parent
//    }

    Image {
        id: image
        antialiasing: true
        anchors.fill: parent
        source: "/resources/boardTile.svg"
    }
}
